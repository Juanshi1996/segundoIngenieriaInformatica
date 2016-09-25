#include "subject.hpp"
#include <stdio.h>
#include "persistenceManager.hpp"
#include "functions.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "macros.hpp"
#include <string.h>


int main(int argc, char const *argv[]) {
  int option;
  ds::Subject subject;
  edi::Persona p1;
  edi::LinkedOrderedBinaryTree<ds::Key>* tree = new edi::LinkedOrderedBinaryTree<ds::Key>;
  ds::DoublyLinkedSortedList<edi::Persona> list;
  ds::DoublyLinkedSortedList<edi::Persona>* auxList;
  ds::Key auxKey;
  char fileName[30];
  int DNI;
  char fileTxt[30];
  char fileIdx[30];
  char file[] = "personas.txt";
  do{
    BORRAR;
    std::cout << std::endl << "----------- MENU -----------" << std::endl;
    std::cout << "1.- Create new subject." << std::endl;
    std::cout << "2.- Save subject." << std::endl;
    std::cout << "3.- Load subject." << std::endl;
    std::cout << "4.- Search student in subject." << std::endl;
    std::cout << "5.- Show subject." << std::endl;
    std::cout << "SELECT AN OPTION (-1 TO EXIT): " << std::endl;
    std::cin >> option;
    switch(option){
      case 1: //NEW SUBJECT
        int n;
        std::cout << "How many students? ";
        std::cin >> n;
        subject.createSubject(n, file);
        list = subject.getStudents();
        createTree(&list, tree);
        std::cout << "Subject created" << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;

      case 2: //SAVE SUBJECT
        std::cout << "Introduce filename (without extension): ";
        std::cin >> fileName;
        strcpy(fileTxt, fileName);
        strcpy(fileIdx, fileName);
        strcat(fileTxt, ".txt");
        strcat(fileIdx, ".idx");
        list = subject.getStudents();
        saveList(list, fileTxt);
        saveTree(tree, fileIdx);
        std::cout << "Subject saved!" << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;

      case 3: //LOAD SUBJECT
        std::cout << "Introduce filename (without extension): ";
        std::cin >> fileName;
        strcpy(fileTxt, fileName);
        strcpy(fileIdx, fileName);
        strcat(fileTxt, ".txt");
        strcat(fileIdx, ".idx");
        auxList = subject.getStudentsP();
        loadList(auxList, fileTxt);
        loadTree(tree, fileIdx);
        std::cout << "Subject loaded!" << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;

      case 4: //Search student
        std::cout << "DNI of the student to search: ";
        std::cin >> DNI;
        list = subject.getStudents();
        auxKey.setDNI(DNI);
        if(tree->has(auxKey)){
          tree->search(auxKey);
          auxKey = tree->item();
          p1 = list.getItem(auxKey.getPosition());
          std::cout << p1;
        }
        else{
          std::cout << "DNI not found." << std::endl;
        }
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;

      case 5: //UPWARD LIST (SHOW SUBJECT)
        BORRAR;
        subject.upwardlyList(subject.getStudents());
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;

      case -1:
        std::cout << "Bye!" << std::endl;
      break;

      default:
        std::cout << "Not valid option, try again!" << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
        getchar();
      break;
    }
  }while(option != -1);
  return 0;
}
