/*!\file dis_SortedList.hpp
   \brief
   \author Víctor Monserrat Villatoro
   \date 07-03-2015*/

#ifndef __DIS_SORTED_LIST_HPP__
#define __DIS_SORTED_LIST_HPP__

/*!\namespace dis
   \brief Namespace for Data and Information Structure subject.*/
namespace dis {
  /*!\class SortedList
     \brief Abstrast template class to model the SortedList[T] ADT.*/
  template <class T>
  class SortedList {
  /*!\name Public functions or class methods of SortedList:*/
  public:
  /*!\name Destroyer:@{*/
  /*!\fn ~SortedList()
     \brief Destroy the list.
      Time analysis: O(1).
     \warning The onwer data structure will have the responsability of
      deallocating the linked memory.
     \pre None.
     \post None.*/
    virtual ~SortedList() {
    }
  /*@}*/
  /*!\name Observers:@{*/
  /*!\fn bool isLast(int const &position)
     \brief Is position the last list's position?
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre None.
     \post None.
     \return true if pos is a valid list's position.*/
    virtual bool isLast(int const &position) = 0;
  /*!\fn bool isValid(int const &position)
     \brief Get the item at a given position.
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre None.
     \post None.
     \return true if pos is a valid list's position.*/
    virtual bool isValid(int const &position) = 0;
  /*!\fn T const &getItem(int const &position)
     \brief Get the item at a given position.
      Time analysis: O(n).
     \arg[in] position is the list's position.
     \pre isValid(pos)
     \post None.
     \return a const reference to the stored.*/
    virtual T const &getItem(int const &position) = 0;
  /*!\fn int findItem(T const &item, int const &from)
     \brief Find the position of a given item.
      Time analysis: O(n).
     \arg[in] item is the data to be found.
     \arg[in] from give a position to start the search.
     \pre isValid(from)
     \post returnValue>=0 implies isValid(returnValue)
     \post returnValue>=0 implies getItem(returnValue)=item
     \return return -1 if it does not found or the item's position.*/
    virtual int findItem(T const &item, int const &from) = 0;
  /*@}*/
  /*!\name Mutators:@{*/
  /*!\fn void insert(T const &item)
     \brief Insertes item orderly.
      Time analysis: O(n).
     \arg[in] item is the item to store.
     \pre None.
     \post isValid(findItem(item)-1) implies item >= getItem(findItem(item)-1));
     \post isValid(findItem(item)+1) implies item <= getItem(findItem(item)+1));
  */
    virtual void insert(T const &item) = 0;
  /*!\fn void deletePosition(int const &position)
     \brief Deletes the given position.
      Time analysis: O(n).
     \arg[in] position is the position to be deleted.
     \pre not isEmpty()
     \post savedCurrent.isLast(position) implies not isValid(position)
     \post position=0 and savedCurrent.isLast(position) implies isEmpty()
     \post not savedCurrent.isLast(position) implies
      getItem(position)=savedCurrent.item(position+1)*/
    virtual void deletePosition(int const &position) = 0;
  /*@}*/
}; /*!class SortedList*/
} /*!namespace dis*/

#endif /*!__DIS_SORTED_LIST_HPP__*/
