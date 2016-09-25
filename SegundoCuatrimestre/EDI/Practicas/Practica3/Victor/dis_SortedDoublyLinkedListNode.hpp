/*!\file dis_SortedDoublyLinkedListNode.hpp
   \brief
   \author Víctor Monserrat Villatoro
   \date 07-03-2015*/

#ifndef __DIS_SORTED_DOUBLY_LINKED_LIST_NODE_HPP__
#define __DIS_SORTED_DOUBLY_LINKED_LIST_NODE_HPP__

/*!\namespace dis
   \brief Namespace for Data and Information Structure subject.*/
namespace dis {
  /*!\class SortedDoublyLinkedListNode
     \brief Implements the DoublyLinkedNode[T] ADT used in linked versions of
      lineal data structured.*/
  template <class T>
  class SortedDoublyLinkedListNode {
  /*!\name Public functions or class methods of SortedDoublyLinkedListNode:*/
  public:
  /*!\name Makers:@{*/
  /*!\fn SortedDoublyLinkedListNode(const T &item,
                                    SortedDoublyLinkedListNode<T> *next,
                                    SortedDoublyLinkedListNode<T> *previous)
     \brief Makes a LinkedNode.
      Time analysis: 0(1).
     \arg[in] item is the data to be stored.
     \arg[in] next is the link with the next element.
     \arg[in] previous is the link with the previous element.
     \pre None.
     \post None.*/
    SortedDoublyLinkedListNode(const T &item,
                               SortedDoublyLinkedListNode<T> *next,
                               SortedDoublyLinkedListNode<T> *previous) {
      _item = item;
      _next = next;
      _previous = previous;
    }
  /*@}*/
  /*!\name Destroyer:@{*/
  /*!\fn ~SortedDoublyLinkedListNode()
     \brief Destroy the node.
      Time analysis: O(1).
     \warning The onwer data structure will have the responsability of
      deallocating the linked memory.
     \pre None.
     \post None.*/
    virtual ~SortedDoublyLinkedListNode() {}
  /*@}*/
  /*!\name Observers:@{*/
  /*!\fn T const &getItem() const
     \brief Gets the stored data.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const reference to the data.*/
    virtual inline T const &getItem() const {return(_item);}
  /*!\fn SortedDoublyLinkedListNode<T> const *getNext() const
     \brief Gets a link to next element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to next element.*/
    virtual SortedDoublyLinkedListNode<T> const *getNext() const {
      return(_next);
    }
  /*!\fn SortedDoublyLinkedListNode<T> *getNext()
     \brief Gets a link to next element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a pointer to next element.*/
    virtual SortedDoublyLinkedListNode<T> *getNext() {
      return(_next);
    }
  /*!\fn SortedDoublyLinkedListNode<T> const *getPrevious() const
     \brief Gets a link to previous element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a const pointer to previous element.*/
    virtual SortedDoublyLinkedListNode<T> const *getPrevious() const {
      return(_previous);
    }
  /*!\fn SortedDoublyLinkedListNode<T> *getPrevious()
     \brief Gets a link to previous element.
      Time analysis: O(1).
     \pre None.
     \post None.
     \return a pointer to previous element.*/
    virtual SortedDoublyLinkedListNode<T> *getPrevious() {
      return(_previous);
    }
  /*@}*/
  /*!\name Mutators:@{*/
  /*!\fn void setItem(T const &item)
     \brief Sets the stored data.
      Time analysis: O(1).
     \arg[in] item is the data to be stored.
     \pre None.
     \post None.*/
    virtual inline void setItem(T const &item) {_item = item;}
  /*!\fn void setNext(SortedDoublyLinkedListNode<T> *next)
     \brief Sets the link to next element.
      Time analysis: O(1).
     \arg[in] next is a reference to next operator.
     \pre None.
     \post None.*/
    virtual void setNext(SortedDoublyLinkedListNode<T> *next) {
      _next = next;
    }
  /*!\fn void setPrevious(SortedDoublyLinkedListNode<T> *previous)
     \brief Sets the link to previous element.
      Time analysis: O(1).
     \arg[in] previous is a reference to next operator.
     \pre None.
     \post None.*/
    virtual void setPrevious(SortedDoublyLinkedListNode<T> *previous) {
      _previous = previous;
    }
  /*@}*/
  /*!\name Private attributes of the class SortedDoublyLinkedListNode:*/
  private:
  /*!\var T _item
     \brief The stored data.*/
    T _item;
  /*!\var SortedDoublyLinkedListNode<T> *_next
     \brief A pointer to next element.*/
    SortedDoublyLinkedListNode<T> *_next;
  /*!\var SortedDoublyLinkedListNode<T> *_previous
     \brief A pointer to previous element.*/
    SortedDoublyLinkedListNode<T> *_previous;
  }; /*!class SortedDoublyLinkedListNode*/
} /*!namespace dis*/

#endif /*!__DIS_SORTED_DOUBLY_LINKED_LIST_NODE_HPP__*/
