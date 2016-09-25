#include <fstream>
#include <iostream>
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "edi_OrderedBinaryTree.hpp"
#include "edi_LinkedBinaryTree.hpp"
#include "clave.hpp"

namespace edi{
  std::ofstream &operator<< (std::ofstream& out, const LinkedOrderedBinaryTree<Clave> &t){
    out << " " << t.item().dni() << "," << t.item().numero() << " ";
    //std::cout << "numero: " << t.item().numero() << " " << "dni: " << t.item().dni() << std::endl;
    return out;
  };


  std::ifstream &operator>> (std::ifstream& in, LinkedOrderedBinaryTree<Clave> &t){
    edi::Clave c;
    char var[20];
    in >> var;
    if (strcmp(var, "a")!=0){
      c.dni(atoi(var));
      in >> var;
      c.numero(atoi(var));
      t.insert(c);
    }

    //std::cout << "numero: " << t.item().numero() << " " << "dni: " << t.item().dni() << std::endl;
    return in;
  };
}
