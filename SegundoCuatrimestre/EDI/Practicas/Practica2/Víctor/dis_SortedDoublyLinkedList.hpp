/*!\file dis_SortedDoublyLinkedList.hpp
   \brief
   \author Víctor Monserrat Villatoro
   \date 07-03-2015*/

#ifndef __DIS_SORTED_DOUBLY_LINKED_LIST_HPP__
#define __DIS_SORTED_DOUBLY_LINKED_LIST_HPP__

#include "dis_SortedList.hpp"
#include "dis_SortedDoublyLinkedListNode.hpp"
#include <cassert>
#include <cstring>

/*!\namespace dis
   \brief Namespace for Data and Information Structure subject.*/
namespace dis {
  /*!\class SortedDoublyLinkedList
     \brief Implements the SortedList[T] ADT as a sorted doubly linked list.*/
  template <class T>
  class SortedDoublyLinkedList : public dis::SortedList<T> {
  /*!\name Public functions or class methods of SortedDoublyLinkedList:*/
  public:
  /*!\name Makers:@{*/
  /*!\fn SortedDoublyLinkedList()
     \brief Makes a new list.
      Time analysis: O(1).
     \pre None.
     \post isEmpty()*/
    SortedDoublyLinkedList() {
      _head = NULL;
      _current = NULL;
      assert(isEmpty());
    }
  /*@}*/
  /*!\name Destroyer:@{*/
  /*!\fn ~SortedDoublyLinkedList()
     \brief Deallocate the list.
      Time analysis: O(n).
     \pre None.
     \post None.*/
    virtual ~SortedDoublyLinkedList() {
      if(_head != NULL) {
        _current = _head;
        while(_current->getNext() != NULL) {
          _current = _current->getNext();
          delete _current->getPrevious();
        }
        delete _current;
        _head = NULL;
      }
    }
  /*@}*/
  /*!\name Observers:@{*/
  /*!\fn dis::SortedDoublyLinkedListNode<T> const *getHead() const
     \brief Gets a link to first element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to first element.*/
    virtual dis::SortedDoublyLinkedListNode<T> const *getHead() const {
      return(_head);
    }
  /*!\fn dis::SortedDoublyLinkedListNode<T> *getHead()
     \brief Gets a link to first element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to first element.*/
    virtual dis::SortedDoublyLinkedListNode<T> *getHead() {
      return(_head);
    }
  /*!\fn dis::SortedDoublyLinkedListNode<T> const *getCurrent() const
     \brief Gets a link to current element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to current element.*/
    virtual dis::SortedDoublyLinkedListNode<T> const *getCurrent() const {
      return(_current);
    }
  /*!\fn dis::SortedDoublyLinkedListNode<T> *getCurrent()
     \brief Gets a link to current element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to current element.*/
    virtual dis::SortedDoublyLinkedListNode<T> *getCurrent() {
      return(_current);
    }
  /*!\fn bool isEmpty() const
     \brief Is the list empty?
      Time analysis: O(1).
     \pre None.
     \post None.
     \return true if the list is empty.*/
    virtual bool isEmpty() const
    {
      return(_head==NULL);
    }
  /*!\fn bool isLast(int const &position)
     \brief Is position the last list's position?
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre None.
     \post None.
     \return true if the position is the last.*/
    virtual bool isLast(int const &position) {
      assert(isValid(position));
      dis::SortedDoublyLinkedListNode<T> *savedCurrent = _current;
      goTo(position);
      bool returnValue = _current->getNext() == NULL;
      _current = savedCurrent;
      return(returnValue);
    }
  /*!\fn bool isValid(int const &position)
     \brief Is position a valid list's position?
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre None.
     \post None.
     \return true if position is a valid list's position.*/
    virtual bool isValid(int const &position) {
      dis::SortedDoublyLinkedListNode<T> *savedCurrent = _current;
      goTo(position);
      bool returnValue = _current != NULL;
      _current = savedCurrent;
      return(returnValue);
    }
  /*!\fn T const &getItem(int const &position)
     \brief Get the item at a given position.
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre isValid(pos)
     \post None.
     \return a const reference to the stored.*/
    virtual T const &getItem(int const &position) {
      assert(isValid(position));
      dis::SortedDoublyLinkedListNode<T> *savedCurrent = _current;
      goTo(position);
      T const &returnValue = _current->getItem();
      _current = savedCurrent;
      return(returnValue);
    }
  /*!\fn int findItem(T const &item, int const &from)
     \brief Find the position of a given item.
      Time analysis: O(n).
     \arg[in] item is the data to be found.
     \arg[in] from give a position to start the search.
     \pre isValid(from)
     \post returnValue>=0 implies isValid(returnValue)
     \post returnValue>=0 implies getItem(returnValue)=item
     \return return -1 if it does not found or the item's position.*/
    virtual int findItem(T const &item, int const &from = 0) {
      assert(isValid(from));
      int returnValue = -1;
      dis::SortedDoublyLinkedListNode<T> *savedCurrent = _current;
      goTo(from);
      for(size_t i = from; returnValue == -1 and _current != NULL; i++) {
        if(_current->getItem() == item) {
          returnValue = i;
        } else {
          _current = _current->getNext();
        }
      }
      _current = savedCurrent;
      assert(returnValue == -1 or (isValid(returnValue) and getItem(returnValue)
      == item));
      return(returnValue);
    }
  /*@}*/
  /*!\name Mutators:@{*/
  /*!\fn void setHead(dis::SortedDoublyLinkedListNode<T> *head)
     \brief Sets the link to first element.
      Time analysis: O(1).
     \arg[in] head is a reference to first operator.
     \pre None.
     \post None.*/
    virtual void setHead(dis::SortedDoublyLinkedListNode<T> *head) {
      _head = head;
    }
  /*!\fn void setCurrent(dis::SortedDoublyLinkedListNode<T> *current)
     \brief Sets the link to current element.
      Time analysis: O(1).
     \arg[in] current is a reference to current operator.
     \pre None.
     \post None.*/
    virtual void setCurrent(dis::SortedDoublyLinkedListNode<T> *current) {
      _current = current;
    }
  /*!\fn void insert(T const &item)
     \brief Insertes item orderly.
      Time analysis: O(n).
     \arg[in] item is the item to store.
     \pre None.
     \post isValid(findItem(item)-1) implies item >= getItem(findItem(item)-1));
     \post isValid(findItem(item)+1) implies item <= getItem(findItem(item)+1));
  */
    virtual void insert(T const &item) {
      bool insertedItem = false;
      if(isEmpty()) {
        _head = new dis::SortedDoublyLinkedListNode<T>(item, NULL, NULL);
        _current = _head;
        insertedItem = true;
      }
      else {
        if(_current == NULL) {
          _current = _head;
        }
        while(!insertedItem) {
          if(item < _current->getItem()) {
            if(_current->getPrevious() == NULL) {
              _head = new dis::SortedDoublyLinkedListNode<T>(item, _head, NULL);
              _current->setPrevious(_head);
              _current = _head;
              insertedItem = true;
            }
            else if(item >= _current->getPrevious()->getItem()) {
              _current->getPrevious()->setNext(new
              dis::SortedDoublyLinkedListNode<T>(item, _current,
              _current->getPrevious()));
              _current = _current->getPrevious()->getNext();
              _current->getNext()->setPrevious(_current);
              insertedItem = true;
            } else {
              _current = _current->getPrevious();
            }
          } else {
            if(_current->getNext() == NULL) {
              _current->setNext(new dis::SortedDoublyLinkedListNode<T>(item,
              NULL, _current));
              _current = _current->getNext();
              insertedItem = true;
            }
            else if(item <= _current->getNext()->getItem()) {
              _current->setNext(new dis::SortedDoublyLinkedListNode<T>(item,
              _current->getNext(), _current));
              _current = _current->getNext();
              _current->getNext()->setPrevious(_current);
              insertedItem = true;
            } else {
              _current = _current->getNext();
            }
          }
        }
      }
      #ifndef NDEBUG
        int itemPosition = findItem(item);
        assert(not isValid(itemPosition-1) or item >= getItem(itemPosition-1));
        assert(not isValid(itemPosition+1) or item <= getItem(itemPosition+1));
      #endif
    }
  /*!\fn void deletePosition(int const &position)
     \brief Deletes the given position.
      Time analysis: O(n).
     \arg[in] position is the position to be deleted.
     \pre not isEmpty()
     \post savedCurrent.isLast(position) implies not isValid(position)
     \post position=0 and savedCurrent.isLast(position) implies isEmpty()
     \post not savedCurrent.isLast(position) implies
      getItem(position)=savedCurrent.item(position+1)*/
    virtual void deletePosition(int const &position) {
      assert(!isEmpty());
      assert(isValid(position));
      #ifndef NDEBUG
        bool oldIsLast = !isValid(position+1);
        T oldItemNext = T();
        if(not oldIsLast) {
          oldItemNext = getItem(position+1);
        }
      #endif
      dis::SortedDoublyLinkedListNode<T> *savedCurrent = _current;
      goTo(position);
      if(_current->getPrevious() == NULL) {
        _head = _current->getNext();
      } else {
        _current->getPrevious()->setNext(_current->getNext());
      }
      delete _current;
      _current = savedCurrent;
      #ifndef NDEBUG
        assert(oldIsLast or getItem(position) == oldItemNext);
      #endif
    }
  /*!\name Protected functions or class methods of SortedDoublyLinkedListNode:*/
  protected:
  /*!\fn void goTo(unsigned const &index)
     \brief Go to a given list's position.
      Time analysis: O(n).
     \warning If it does not exist, _current will be a null pointer.
     \pre None.
     \post None.*/
    virtual void goTo(unsigned const &index) {
      _current = _head;
      for(size_t i = 0; i < index and _current != NULL; i++) {
        _current = _current->getNext();
      }
    }
  /*@}*/
  /*!\name Private attributes of the class SortedDoublyLinkedList:*/
  private:
  /*!\var dis::SortedDoublyLinkedListNode<T> *_head
     \brief A pointer to first element.*/
    dis::SortedDoublyLinkedListNode<T> *_head;
  /*!\var dis::SortedDoublyLinkedListNode<T> *_current
     \brief A pointer to current element.*/
    dis::SortedDoublyLinkedListNode<T> *_current;
  }; /*!\class SortedDoublyLinkedList*/
} /*!namespace dis*/

#endif /*!__DIS_SORTED_DOUBLY_LINKED_LIST_HPP__*/
