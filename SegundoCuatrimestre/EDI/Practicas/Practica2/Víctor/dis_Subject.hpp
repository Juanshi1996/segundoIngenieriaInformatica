/*!\file dis_Subject.hpp
   \brief
   \author Víctor Monserrat Villatoro
   \date 07-03-2015*/

#ifndef __DIS_SUBJECT_HPP__
#define __DIS_SUBJECT_HPP__

#include "dis_SortedDoublyLinkedList.hpp"
#include "persona.hpp"
#include <vector>
#include <iostream>

/*!\namespace dis
   \brief Namespace for Data and Information Structure subject.*/
namespace dis {
  /*!\class Subject
     \brief Implements the Subject as a SortedDoublyLinkedList[Persona].*/
  class Subject {
  /*!\name Public functions or class methods of Subject:*/
  public:
  /*!\name Makers:
  @{*/
  /*!\fn Subject(std::vector<edi::Persona> const students)
     \brief Makes a new subject.
      Time analysis: O(n).
     \arg[in] students is the Persona's STD vector.
     \pre None.
     \post None.*/
    Subject(std::vector<edi::Persona> const students) {
      for(size_t i = 0; i < students.size(); i++) {
        _students.insert(students[i]);
      }
    }
  /*@}*/
  /*!\name Destroyer:@{*/
  /*!\fn ~Subject()
     \brief Destroy the subject.
      Time analysis: O(1).
     \pre None.
     \post None.*/
    ~Subject() {
      delete this;
    }
  /*@}*/
  /*!\name Observers:@{*/
  /*!\fn void listUpwardlySorted()
     \brief List upwardly sorted the students.
      Time analysis: O(n).
     \pre None.
     \post None.*/
    void listUpwardlySorted() {
      dis::SortedDoublyLinkedListNode<edi::Persona> *savedCurrent =
      _students.getCurrent();
      _students.setCurrent(_students.getHead());
      std::cout << "\n";
      while(_students.getCurrent() != NULL) {
        std::cout << "     " << _students.getCurrent()->getItem();
        _students.setCurrent(_students.getCurrent()->getNext());
      }
      _students.setCurrent(savedCurrent);
    }
  /*!\fn void listDescendentSorted()
     \brief List descendent sorted the students.
      Time analysis: O(n).
     \pre None.
     \post None.*/
    void listDescendentSorted() {
      dis::SortedDoublyLinkedListNode<edi::Persona> *savedCurrent =
      _students.getCurrent();
      _students.setCurrent(_students.getHead());
      while(_students.getCurrent()->getNext() != NULL) {
        _students.setCurrent(_students.getCurrent()->getNext());
      }
      std::cout << "\n";
      while(_students.getCurrent() != NULL) {
        std::cout << "     " << _students.getCurrent()->getItem();
        _students.setCurrent(_students.getCurrent()->getPrevious());
      }
      _students.setCurrent(savedCurrent);
    }
  /*!\fn void showUpwardlySortedbetweenTwoStudents(edi::Persona const &p,
                                                   edi::Persona const &q)
     \brief Show upwardly sorted the students between others two.
      Time analysis: O(n).
     \arg[in] p is one of the two students.
     \arg[in] q is the other of the two students.
     \pre None.
     \post None.*/
    void showUpwardlySortedbetweenTwoStudents(edi::Persona const &p,
                                              edi::Persona const &q) {
      size_t i = _students.findItem(p, 0);
      size_t j = _students.findItem(q, 0);
      while(i+1 < j) {
        std::cout << "     " << _students.getItem(i+1);
        i++;
      }
      while(j+1 < i) {
        std::cout << "     " << _students.getItem(j+1);
        j++;
      }
    }
  /*!\fn void showDescendentSortedbetweenTwoStudents(edi::Persona const &p,
                                                     edi::Persona const &q)
     \brief Show descendent sorted the students between others two.
      Time analysis: O(n).
     \arg[in] p is one of the two students.
     \arg[in] q is the other of the two students.
     \pre None.
     \post None.*/
    void showDescendentSortedbetweenTwoStudents(edi::Persona const &p,
                                                edi::Persona const &q) {
      size_t i = _students.findItem(p, 0);
      size_t j = _students.findItem(q, 0);
      while(i-1 > j) {
        std::cout << "     " << _students.getItem(i-1);
        i--;
      }
      while(j-1 > i) {
        std::cout << "     " << _students.getItem(j-1);
        j--;
      }
    }
    /*!\fn bool isStudent(edi::Persona const &p)
       \brief Is student at subject?
        Time analysis: O(n).
       \arg[in] p is the students to check.
       \pre None.
       \post None.
       \return true if student is at subject.*/
    bool isStudent(edi::Persona const &p) {
      if(_students.findItem(p, 0) == -1) {
        return(false);
      } else {
        return(true);
      }
    }
  /*@}*/
  /*!\name Mutators:@{*/
  /*!\fn void modifyStudent(edi::Persona const &p)
     \brief Modify the basic information of a student.
      Time analysis: O(n).
     \arg[in] p is the student to modify.
     \pre None.
     \post None.*/
    void modifyStudent(edi::Persona const &p) {
      edi::Persona q;
      std::cout << "\n     Introduzca los nuevos datos del alumno...\n";
      std::cin >> q;
      _students.deletePosition(_students.findItem(p, 0));
      _students.insert(q);
    }
  /*!\name Private attributes of the class Subject:*/
  private:
  /*!\var dis::SortedDoublyLinkedList<edi::Persona> _students
     \brief A Sorted doubly linked list of people.*/
    dis::SortedDoublyLinkedList<edi::Persona> _students;
  }; /*!\class Subject*/
} /*!namespace dis*/

#endif /*!__DIS_SUBJECT_HPP__*/
