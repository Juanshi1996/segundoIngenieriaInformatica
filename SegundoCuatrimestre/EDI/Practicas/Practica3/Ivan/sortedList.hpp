/*!
  \file sortedList.hpp
  \brief
  \author Iván Portillo Leal
*/
#ifndef SORTEDLIST_HPP_
#define SORTEDLIST_HPP_

/*!\namespace ds
  \brief Namespace to the Data Structures subject
*/
namespace ds{
  /*!\class Node
     \brief Class defining a sorted list
  */
  template<class T>
  class SortedList{
  /*!\name Public part of the class SortedList:*/
  public:
    /*!\name Makers:
      @{*/
    SortedList(){};
    /*@}*/
    /*!\name Getters:
      @{*/
      /*!\fn bool isLast(const int &pos)
         \brief Return true if the element in position pos is the last
      */
    virtual bool isLast(const int &pos) = 0;
    /*!\fn bool isValid(const int &pos)
       \brief Return true if the element in position pos is valid
    */
    virtual bool isValid(const int &pos) = 0;
    /*!\fn T getItem(const int &pos)
       \brief Gets the data of the element in the position pos
    */
    virtual T getItem(const int &pos) = 0;
    /*!\fn T getItem(const int &pos)
       \brief Gets the position of the element item
    */
    virtual int searchItem(const T &item, const int &from) = 0;
    /*@}*/
    /*!\name Setters:
      @{*/
      /*!\fn void insert(const T &item)
         \brief Insert a element in the list
      */
    virtual void insert(const T &item) = 0;
    /*!\fn void deletePosition(const int &pos)
       \brief Delete a element in the position pos in the list
    */
    virtual void deletePosition(const int &pos) = 0;
    /*@}*/
  };
}

#endif
