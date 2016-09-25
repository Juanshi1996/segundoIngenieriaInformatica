#include "subject.hpp"
#include "generarpersona.hpp"
#include <vector>

using namespace ds;

void Subject::createSubject(int nstudents, char* file){
  int i;
  std::vector<edi::Persona> vStudents = generarPersonas(file, nstudents);

  for(i=0; i<nstudents; i++){
    std::cout << vStudents[i] << std::endl;
    insertStudent(vStudents[i]);
  }
}

void Subject::insertStudent(const edi::Persona &student){
  _students.insert(student);
}

void Subject::upwardlyList(DoublyLinkedSortedList<edi::Persona> studentsList){
  Node<edi::Persona>* aux;
  aux = studentsList.getCurrent();
  studentsList.setCurrent(studentsList.getHead());
  while(studentsList.getCurrent() != NULL){
    std::cout << studentsList.getCurrent()->getData();
    studentsList.setCurrent(studentsList.getCurrent()->getNext());
  }
  studentsList.setCurrent(aux);
}

void Subject::descendentList(DoublyLinkedSortedList<edi::Persona> studentsList){
  Node<edi::Persona>* aux;
  aux = studentsList.getCurrent();
  studentsList.setCurrent(studentsList.getHead());
  while(studentsList.getCurrent()->getNext() != NULL){
    studentsList.setCurrent(studentsList.getCurrent()->getNext());
  }
  while(studentsList.getCurrent() != NULL){
    std::cout << studentsList.getCurrent()->getData();
    studentsList.setCurrent(studentsList.getCurrent()->getPrevious());
  }
  studentsList.setCurrent(aux);
}

DoublyLinkedSortedList<edi::Persona> Subject::extractStudents(const edi::Persona &p1, const edi::Persona &p2){
  DoublyLinkedSortedList<edi::Persona> auxList;
  int pos1, pos2, i;
  pos1 = _students.searchItem(p1, 0);
  pos2 = _students.searchItem(p2, pos1);

  for(i=pos1+1; i<pos2; i++){
    auxList.insert(_students.getItem(i));
  }
  return auxList;
}

void Subject::modifyStudent(const edi::Persona &s){
  edi::Persona aux;
  std::cout << "Insert the new data of the student: " << std::endl;
  std::cin >> aux;
  _students.deletePosition(_students.searchItem(s, 0));
  _students.insert(aux);
}
