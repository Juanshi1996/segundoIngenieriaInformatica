/*!
  \file doublyLinkedSortedList.hpp
  \brief
  \author Iván Portillo Leal
*/

#ifndef DOUBLYLINKEDSORTEDLIST_HPP_
#define DOUBLYLINKEDSORTEDLIST_HPP_

#include "sortedList.hpp"
#include "node.hpp"
#include <cassert>
#include <iostream>

/*!\namespace ds
  \brief Namespace to the Data Structures subject
*/
namespace ds{
  /*!\class DoublyLinkedSortedList
     \brief Class defining a doubly linked sorted list
  */
  template<class T>
  class DoublyLinkedSortedList : public SortedList<T>{
  /*!\name Private part of the class DoublyLinkedSortedList:*/
  private:
    /*!\var Node<T>* head_
        \brief Pointer to the head of the list.
    */
    Node<T>* head_;
    /*!\var Node<T>* current_
        \brief Pointer to the current element of the list.
    */
    Node<T>* current_;

  /*!\name Protected part of the class DoublyLinkedSortedList:*/
  protected:
    /*!\fn void goTo(const int &pos)
       \brief Sets the current pointer to the element in the position pos.
       \pre Nothing
       \post Nothing
    */
    void goTo(const int &pos) {
      setCurrent(head_);
      int i = 0;
      while(i<pos && getCurrent() != NULL){
        setCurrent(getCurrent()->getNext());
        i++;
      }
    }

  public:
    /*!\name Makers:
      @{*/
      /*!\fn DoublyLinkedSortedList()
         \brief Generates a list
         \pre Nothing
         \post Nothing
      */
    DoublyLinkedSortedList(){
      head_ = NULL;
      current_ = NULL;
    }
    /*@}*/

    /*!\name Getters:
      @{*/
      /*!\fn Node<T>* getHead()
         \brief Return the first element of the list.
         \pre Nothing
         \post Nothing
         \return Pointer to the head of the list.
      */
    inline Node<T>* getHead() const { return head_; };
    /*!\fn Node<T>* getCurrent()
       \brief Return the current element of the list
       \pre Nothing
       \post Nothing
       \return Pointer to the current element of the list.
    */
    inline Node<T>* getCurrent() const{ return current_; };
    /*!\fn bool isLast(const int &pos)
       \arg[pos] position in the list
       \brief Return true if the element in pos is the last element in the list.
       \pre isValid(pos)
       \post Nothing
       \return A boolean indicating if the element in pos is the last.
    */
    bool isLast(const int &pos){
      assert(isValid(pos));
      Node<T>* aux = getCurrent();
      goTo(pos);
      bool last = (current_->getNext() == NULL);
      setCurrent(aux);
      return last;
    }
    /*!\fn bool isValid(const int &pos)
       \brief Return true if the element in pos is valid.
       \arg[pos] position in the list
       \pre Nothing
       \post Nothing
       \return A boolean indicating if the element in pos is a valid element of the list.
    */
    bool isValid(const int &pos) {
      Node<T>* aux;
      bool currentZero = 0;
      aux = getCurrent();
      goTo(pos);
      if(getCurrent() != NULL){
        currentZero = 1;
      }
      setCurrent(aux);
      return currentZero;
    }
    /*!\fn T getItem(const int &pos)
       \brief Return the element in the position pos.
       \arg[pos] position in the list
       \pre isValid(pos)
       \post Nothing
       \return A boolean indicating if the element in pos is a valid element of the list.
    */
    T getItem(const int &pos) {
      assert(isValid(pos));
      Node<T>* aux;
      T data;
      int i = 0;
      aux = getCurrent();
      setCurrent(getHead());
      while(i<pos){
        setCurrent(getCurrent()->getNext());
        i++;
      }
      if(getCurrent() != NULL){
        data = getCurrent()->getData();
      }
      setCurrent(aux);
      return data;
    }
    /*!\fn int searchItem(const T &item, const int &from)
       \brief Return position of a element in the list.
       \arg[pos] position in the list
       \arg[from] initial position to search the element.
       \pre isValid(from)
       \post isValid(i) && getItem(i) == item
       \return The position of the element in the list or -1 if it hasn't been found.
    */
    int searchItem(const T &item, const int &from){
      assert(isValid(from));
      Node<T>* aux = getCurrent();
      int i;
      bool found = 0;

      goTo(from);
      if(getCurrent()->getData() == item){
        found = 1;
      }
      for(i=from; getCurrent()->getNext() != NULL && !found; i++){
        setCurrent(getCurrent()->getNext());
        if(getCurrent()->getData() == item){
          found = 1;
        }
      }
      #ifndef NDEBUG
      if(found){
        assert(isValid(i));
        assert(getItem(i) == item);
      }
      #endif
      setCurrent(aux);
      if(found){
        return i;
      }
      else{
        return -1;
      }
    }
    /*@}*/

    /*!\name Setters:
      @{*/
      /*!\fn void setHead(Node<T>* head)
         \brief Sets the head of the list
         \arg[head] pointer to the element
         \pre Nothing
         \post Nothing
      */
    inline void setHead(Node<T>* head) { head_ = head; };
    /*!\fn void setCurrent(Node<T>* current)
       \brief Sets the current element of the list
       \arg[current] pointer to the element
       \pre Nothing
       \post Nothing
    */
    inline void setCurrent(Node<T>* current) { current_ = current;};
    /*!\fn void insert(const T &item)
       \brief Insert a element in the list orderly.
       \arg[item] Element to introduce
       \pre Nothing
       \post isValid(searchItem(item)-1) == TRUE -> getItem(searchItem(item)-1) <= item
       \post isValid(searchItem(item)+1) == TRUE -> item <= getItem(searchItem(item)+1)
    */
    void insert(const T &item){
      if(getHead() == NULL) //NO NODES - EMPTY LIST
      {
        Node<T>* newNode = new Node<T>(NULL, item, NULL);
        setHead(newNode);
      }
      else{ //+1 NODES IN THE LIST
        Node<T>* aux = getCurrent();
        Node<T>* ant = NULL;
        Node<T>* newNode;
        bool found = 0;
        setCurrent(getHead());
        if(getCurrent()->getData() > item){ //SE INSERTA DELANTE
          newNode = new Node<T>(NULL, item, getHead());
          getHead()->setPrevious(newNode);
          setHead(newNode);
        }
        else{ //INSERTING ORDERED
          while(!found && getCurrent() != NULL){
            if(getCurrent()->getData() > item){
              found = 1;
            }
            else{
              ant = getCurrent();
              setCurrent(getCurrent()->getNext());
            }
          }
          if(getCurrent() != NULL){ //INSERTION IN HALF
            newNode = new Node<T>(getCurrent()->getPrevious(), item, getCurrent());
            (getCurrent()->getPrevious())->setNext(newNode);
            getCurrent()->setPrevious(newNode);
          }
          else{ //INSERTION END
            newNode = new Node<T>(ant, item, ant->getNext());
            ant->setNext(newNode);
          }
        }
        setCurrent(aux);
      }
      #ifndef NDEBUG
      int pos = searchItem(item, 0);
      if(isValid(pos-1)){
        assert(getItem(pos-1) <= item);
      }
      if(isValid(pos+1)){
        assert(item <= getItem(pos+1));
      }
      #endif
    }
    /*!\fn void deletePosition(const int &pos)
       \brief Delete the element in the position pos
       \arg[pos] Position of the element to delete
       \pre getHead() != NULL && isValid(pos) == TRUE
       \post old.isValid(pos+1) = TURE -> new.getItem(pos)=old.getItem(pos+1)
    */
    void deletePosition(const int &pos){
      assert(getHead() != NULL);
      assert(isValid(pos) == 1);
      #ifndef NDEBUG
      T oldItem;
      bool oldIsValid = isValid(pos+1);
      if(oldIsValid){
        oldItem = getItem(pos+1);
      }
      #endif
      Node<T>* aux = getCurrent();
      goTo(pos);
      if(getCurrent() == getHead())
      {
        if(getCurrent()->getNext() != NULL){ //+1 NODE
          (getCurrent()->getNext())->setPrevious(NULL);
          setHead(getCurrent()->getNext());
        }
        else{
          setHead(NULL);
        }
      }
      else{
        if(getCurrent()->getNext() != NULL){
          (getCurrent()->getPrevious())->setNext(getCurrent()->getNext());
          (getCurrent()->getNext())->setPrevious(getCurrent()->getPrevious());
        }
        else{
          (getCurrent()->getPrevious())->setNext(getCurrent()->getNext());
        }
      }
      delete getCurrent();
      setCurrent(aux);
      #ifndef NDEBUG
      if(oldIsValid){
        assert(getItem(pos) == oldItem);
      }
      #endif
    }
    /*@}*/
  };
}

#endif
