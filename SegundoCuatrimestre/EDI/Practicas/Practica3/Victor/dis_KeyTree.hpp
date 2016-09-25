#ifndef __DIS_KEY_TREE__
#define __DIS_KEY_TREE__

#include "dis_SortedDoublyLinkedList.hpp"
#include "persona.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "dis_Key.hpp"
#include <fstream>
#include <cassert>
#include <iostream>
#include "dis_Subject.hpp"
#include <cstdlib>

void keyTreeFromSortedDoublyLinkedList(dis::SortedDoublyLinkedList<edi::Persona> list, edi::LinkedOrderedBinaryTree<dis::Key> *tree) {
  dis::Key k;
  edi::Persona p;
  list.setCurrent(list.getHead());
  for(size_t i = 0; list.getCurrent() != NULL; i++) {
    p = list.getItem(i);
    k.setId(p.dni());
    k.setPosition(i);
    list.setCurrent(list.getCurrent()->getNext());
    tree->insert(k);
  }
}

std::ofstream& operator<<(std::ofstream &out, const edi::LinkedOrderedBinaryTree<dis::Key> &tree) {
  assert(!tree.isEmpty());
  dis::Key k = tree.item();
  out << "( ";
  out << k.getId();
  out << ",";
  out << k.getPosition();
  out << " ";
  if(tree.hasLeftChild()) {
    out.flush();
    out << *(tree.leftSubTree());
  } else {
    out << ": ";
  }
  if(tree.hasRightChild()) {
    out.flush();
    out << *(tree.rightSubTree());
  } else {
    out << ": ";
  }
  out << ") ";
  return(out);
}

std::ifstream& operator>>(std::ifstream &in, edi::LinkedOrderedBinaryTree<dis::Key> &tree) {
  assert(tree.isEmpty());
  char aux[100];
  dis::Key k;
  //int openCount = 0;  /*'(' count*/
  //int closeCount = 0; /*')' count*/
  //do {
    //openCount++;
  while(!in.eof()) {
    in.getline(aux, 100, ' ');
    in.getline(aux, 100, ',');
    k.setId(atoi(aux));
    in.getline(aux, 100, ' ');
    k.setPosition(atoi(aux));
    tree.insert(k);
    in.getline(aux, 100, '(');
  }
    /*for (size_t i = 0; i < strlen(aux); i++) {
      if(aux[i] == ')') {
        closeCount++;
      }
    }*/
  //} while(openCount != closeCount);
  return(in);
}

#endif
