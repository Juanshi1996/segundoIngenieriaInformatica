/*!
  \file node.hpp
  \brief
  \author Iván Portillo Leal
*/
#ifndef NODE_HPP_
#define NODE_HPP_

/*!\namespace ds
  \brief Namespace to the Data Structure subject
*/
namespace ds{
  /*!\class Node
     \brief Class defining a node of a list
  */
  template<class T>
  class Node{
  /*!\name Private part of the class Node:*/
  private:
    /*!\var Node<T>* previous_
        \brief Pointer to the previous element
    */
    Node<T>* previous_;
    /*!\var T data_
        \brief Data that contain the node
    */
    T data_;
    /*!\var Node<T>* next_
        \brief Pointer to the next element
    */
    Node<T>* next_;
  /*!\name Public part of the class Node:*/
  public:
    /*!\name Getters:
      @{*/
      /*!\fn Node<T>* getPrevious()
         \brief Return previous element
         \pre Nothing
         \post Nothing
         \return Pointer to the previous element
      */
    virtual inline Node<T>* getPrevious() { return previous_; };
    /*!\fn Node<T>* getNext()
       \brief Return next element
       \pre Nothing
       \post Nothing
       \return Pointer to the next element
    */
    virtual inline Node<T>* getNext() { return next_; };
    /*!\fn const T getData()
       \brief Return data of the node
       \pre Nothing
       \post Nothing
       \return Data of the node
    */
    virtual inline const T getData() const { return data_; };
    /*@}*/

    /*!\name Setters:
      @{*/
      /*!\fn void setPrevious(Node<T>* previous)
         \brief Sets previous pointer
         \pre Nothing
         \post Nothing
      */
    virtual inline void setPrevious(Node<T>* previous) { previous_ = previous; };
    /*!\fn void setNext(Node<T>* next)
       \brief Sets next pointer
       \pre Nothing
       \post Nothing
    */
    virtual inline void setNext(Node<T>* next) { next_ = next; };
    /*!\fn void void setData(const T &data)
       \brief Sets data of the node
       \pre Nothing
       \post Nothing
    */
    virtual inline void setData(const T &data) { data_ = data; };
    /*@}*/

    /*!\name Makers:
      @{*/
    Node(Node<T>* previous, const T data, Node<T>* next) : previous_(previous),
    data_(data), next_(next) {};
    /*@}*/

    /*!\name Destroyers:
      @{*/
    virtual ~Node(){};
    /*@}*/
  };
}

#endif
