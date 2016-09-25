/*!
  \file subject.hpp
  \brief
  \author Iván Portillo Leal
*/
#ifndef SUBJECT_HPP_
#define SUBJECT_HPP_

#include "doublyLinkedSortedList.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"
#include <vector>

/*!\namespace ds
  \brief Namespace to the Data Structure subject
*/
namespace ds{
  /*!\class Subject
     \brief Class defining a subject
  */
  class Subject{
    /*!\name Private part of the class Subject:*/
  private:
    /*!\var DoublyLinkedSortedList<edi::Persona> _students
        \brief A list containing the students of the subject
    */
    DoublyLinkedSortedList<edi::Persona> _students;
    /*!\name Public part of the class Subject:*/
  public:
    /*!\fn void createSubject(int nstudents, char* file)
       \brief Create a subject
       \arg[nstudents] number of students
       \arg[file] name of the file
       \pre Nothing
       \post Nothing
    */
    void createSubject(int nstudents, char* file);
    /*!\fn void insertStudent(const edi::Persona &student)
       \brief Insert a student in the subject
       \arg[student] The student to introduce
       \pre Nothing
       \post Nothing
    */
    void insertStudent(const edi::Persona &student);
    /*!\fn void upwardlyList(DoublyLinkedSortedList<edi::Persona> studentsList)
       \brief Show a upwardlyList of the students of the subject
       \arg[studentsList] The students list of the subject
       \pre Nothing
       \post Nothing
    */
    void upwardlyList(DoublyLinkedSortedList<edi::Persona> studentsList);
    /*!\fn void upwardlyList(DoublyLinkedSortedList<edi::Persona> studentsList)
       \brief Show a descendentList of the students of the subject
       \arg[studentsList] The students list of the subject
       \pre Nothing
       \post Nothing
    */
    void descendentList(DoublyLinkedSortedList<edi::Persona> studentsList);
    /*!\fn DoublyLinkedSortedList<edi::Persona> extractStudents(const edi::Persona &p1, const edi::Persona &p2)
       \brief Extracts students between other 2 students
       \arg[p1] First student
       \arg[p2] Second student
       \pre Nothing
       \post Nothing
       \return Students list
    */
    DoublyLinkedSortedList<edi::Persona> extractStudents(const edi::Persona &p1, const edi::Persona &p2);
    /*!\fn void modifyStudent(const edi::Persona &s)
       \brief Modify a student
       \arg[s] student to modify
       \pre Nothing
       \post Nothing
    */
    void modifyStudent(const edi::Persona &s);
    /*!\fn DoublyLinkedSortedList<edi::Persona> getStudents()
       \brief Gets the students list
       \pre Nothing
       \post Nothing
       \return Students list
    */
    inline DoublyLinkedSortedList<edi::Persona> getStudents() { return _students; };
    inline DoublyLinkedSortedList<edi::Persona>* getStudentsP() { return &_students; };
  };
}

#endif
