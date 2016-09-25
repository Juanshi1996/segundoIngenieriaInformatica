#include "functions.hpp"
#include "fstream"

void createTree(ds::DoublyLinkedSortedList<edi::Persona> *studentList, edi::LinkedOrderedBinaryTree<ds::Key> *studentTree){
  int i = 0;
  ds::Node<edi::Persona>* aux;
  aux = studentList->getCurrent();
  studentList->setCurrent(studentList->getHead());
  while(studentList->getCurrent() != NULL){
    ds::Key key;
    key.setDNI(((studentList->getCurrent())->getData()).dni());
    key.setPosition(i);
    studentTree->insert(key);
    studentList->setCurrent(studentList->getCurrent()->getNext());
    i++;
  }
  studentList->setCurrent(aux);
}
