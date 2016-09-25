/*!
  \file persistenceManager.hpp
  \author Iván Portillo Leal
*/
#ifndef PERSISTENCE_MANAGER_HPP_
#define PERSISTENCE_MANAGER_HPP_

#include "doublyLinkedSortedList.hpp"
#include "persona.hpp"
#include "subject.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>


/*!
  \fn        void saveList(ds::DoublyLinkedSortedList<T> &list, char* fileName)
  \brief     Save a list in a file
  \param list List to save
  \param fileName Filename where save the list
  \return    Nothing
*/
template<class T>
void saveList(ds::DoublyLinkedSortedList<T> &list, char* fileName){
  std::ofstream file(fileName);
  int i;
  for(i=0; list.isValid(i); i++){
    file << list.getItem(i);
  }
  file.close();
}


/*!
  \fn        void loadList(ds::DoublyLinkedSortedList<T> *list, char* fileName)
  \param list List where load file
  \param fileName Filename where list is saved
  \brief     Load list from a file
  \return    Nothing
*/
template<class T>
void loadList(ds::DoublyLinkedSortedList<T> *list, char* fileName){
  std::ifstream file(fileName);
  edi::Persona p;

  if(file.is_open()){
    while(file >> p){
      std::cout << p;
      list->insert(p);
    }
    file.close();
  }
}


/*!
  \fn        saveTree(edi::LinkedOrderedBinaryTree<ds::Key> *studentTree, char* fileName)
  \brief     Save a tree in a file
  \param studentTree Tree to save
  \param fileName Filename where save the tree
  \return    Nothing
*/
void saveTree(edi::LinkedOrderedBinaryTree<ds::Key> *studentTree, char* fileName){
  std::ofstream file(fileName);
  if(file.is_open()){
    file << studentTree;
    file.close();
  }
}


/*!
  \fn        void loadTree(edi::LinkedOrderedBinaryTree<ds::Key> *studentTree, char* fileName)
  \brief     Load tree from a file
  \param studentTree Tree loaded
  \param fileName Filename where tree is saved
  \return    Nothing
*/
void loadTree(edi::LinkedOrderedBinaryTree<ds::Key> *studentTree, char* fileName){
  std::ifstream file(fileName);
  if(file.is_open()){
    file >> studentTree;
    file.close();
  }
}

#endif
