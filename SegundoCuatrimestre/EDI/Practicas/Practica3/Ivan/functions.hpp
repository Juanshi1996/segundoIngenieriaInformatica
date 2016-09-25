/*!
  \file functions.hpp
  \author Iván Portillo Leal
*/
#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include "doublyLinkedSortedList.hpp"
#include "persona.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "key.hpp"

/*!
  \fn        void createTree(ds::DoublyLinkedSortedList<edi::Persona> *studentList, edi::LinkedOrderedBinaryTree<ds::Key> *studentTree)
  \brief     Create a tree from a DoublyLinkedSortedList
  \param studentList  List to create the tree
  \param studentTree Tree generated
  \return    Nothing
*/
void createTree(ds::DoublyLinkedSortedList<edi::Persona> *studentList, edi::LinkedOrderedBinaryTree<ds::Key> *studentTree);

#endif
