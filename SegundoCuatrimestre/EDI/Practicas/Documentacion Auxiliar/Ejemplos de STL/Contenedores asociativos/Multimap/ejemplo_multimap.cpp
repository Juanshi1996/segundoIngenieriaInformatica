
/////////////////////////////////
///
/// ejemplo_multimap.cpp
///
///////////////////////////////////

#include <iostream>
#include <map>

#include <algorithm>

#include <numeric>

using namespace std;

/// Prototipos

bool segunda_componente_par ( pair <int, int> dato);
void imprimir_par (pair<int,int> dato);

typedef  multimap <int,int,less<int> > tipo_multimap;

int main()
{
 // Variables multimap
 tipo_multimap v1;
 tipo_multimap v2;
 tipo_multimap v3;

 // Iteradores
 tipo_multimap::iterator p;
 tipo_multimap::reverse_iterator q;

 int i = 0;


 // Inserción de pares de elementos

 for (i = 0; i < 10; i++)
  v1.insert(tipo_multimap::value_type(i%4,i+1));

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;


 //
  if (v1.empty())
    cout << "El multimap v1 está vacío" << endl;
  else
    cout << "El multimap v1 no está vacío" << endl;


  cout << "La longitud máxima del multimap de enteros v1 es: " << v1.max_size() << endl;

  cout << "La longitud actual del multimap de enteros v1 es: " << v1.size() << endl;

  cout << "La longitud actual del multimap de enteros v2 es: " << v2.size() << endl;


 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;

 for (int i = 0; i < 10; i++)
  v2.insert(tipo_multimap::value_type(i/4,i+1));

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir_par);
 cout << endl;

  /// Intercambio
 v1.swap(v2);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;
 

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir_par);
 cout << endl;

 /// Operadores relaciones
  if (v1 < v2)
   cout << " v1 es menor que v2 " << endl;

  if (v1 <= v2)
   cout << " v1 es menor o igual que v2 " << endl;

  if (v1 > v2)
   cout << " v1 es mayor que v2 " << endl;

  if (v1 >= v2)
   cout << " v1 es mayor o igual que v2 " << endl;

  if (v1 == v2)
   cout << " v1 es igual que v2 " << endl;

  if (v1 !=v2)
   cout << " v1 es distinto que v2 " << endl;


 /// Uso de iteradores

  cout << "\n ************************************* \n" ;
  cout << "\n Iteradores " << endl;
  
  cout << "\n iterator " << endl;

  cout << " v1 ";
  for (p=v1.begin(); p != v1.end(); p++)
     cout << "(" << p->first << "," << p->second << ") ";

  cout << endl;

  cout << "\n reverse_iterator " << endl;
  cout << " v1 ";
  for (q = v1.rbegin(); q != v1.rend(); q++)
     cout << "(" << q->first << "," << q->second << ") ";

  cout << endl;


 ////
  cout << "\n Aritmética " << endl;
  p = v1.begin();

  cout << " Contenido de p: first " << (*p).first << " second " << (*p).second <<  endl;
  cout << " Contenido de p++: first " << (*p).first << " second " << (*p++).second <<  endl; 
  cout << " Contenido de ++p: first " << (*(++p)).first << " second " << (*p).second <<  endl; 
  cout << " Contenido de p--: first " << (*p).first << " second " << (*p--).second <<  endl; 
  cout << " Contenido de --p: first " << (*(--p)).first << " second " << (*p).second <<  endl; 



  tipo_multimap::iterator p1;

  cout << " p1 = p " <<  endl;
  p1 = p;


  if (p == p1) 
   cout << " p == p1 " << endl;

  if (p != p1) 
   cout << " p != p1 " << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n ************************************* \n" ;
  cout << "\n Borrar " << endl;

   cout << " v1 ";
   for_each(v1.begin(),v1.end(),imprimir_par);
   cout << endl;

   cout << "\n  v1.erase(0); " << endl;

   v1.erase(0);
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir_par);
  cout << endl;



  p = v1.begin();
  p++;

  cout << "  p = v1.begin() y p++, se va a borrar el elemento *p: (" 
       << (*p).first << "," << (*p).second << ")" <<  endl;
 
  v1.erase(p);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;


  cout << " Se borran todos los elementos de v1 con  v1.erase(v1.begin(),v1.end());" << endl;
  
  v1.erase(v1.begin(),v1.end());

  cout << "\n La longitud actual del multimap de enteros v1 es: " << v1.size() << endl;

  cout << " Se borran todos los elementos de v2 con  v2.clear();" << endl;
  v2.clear();

  cout << " La longitud actual del multimap de enteros v2 es: " << v2.size() << endl;



   //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;

  cout << "\n v1.insert(v1.begin(), 0); " << endl;
  v1.insert(v1.begin(), tipo_multimap::value_type(0,1));
 

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;


 for (int i = 0; i < 10; i++)
  v2.insert(tipo_multimap::value_type(i,2*i));


 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir_par);
 cout << endl;



 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;
  cout << "\n ALGORITMOS INVARIANTES \n";

  v1.clear();
  for (int i = 0; i < 10; i++)
   v1.insert(tipo_multimap::value_type(i,i));


  cout << " for_each e imprimir \n";
  cout << " for_each(v1.begin(),v1.end(),imprimir_par);" << endl;
  for_each(v1.begin(),v1.end(),imprimir_par);


  cout << "\n BUSCAR EN CONTENEDORES NO ORDENADOS \n";

  cout << "\n find" << endl;
  cout << "\n p = find(v1.begin(),v1.end(),tipo_multimap::value_type(3,3));" << endl;
  p = find(v1.begin(),v1.end(),tipo_multimap::value_type(3,3));


  cout << "\n for_each(p,v1.end(),imprimir_par);" << endl;
  for_each(p,v1.end(),imprimir_par);
  cout << endl;

  cout << "\n p = find(v1.begin(),v1.end(),tipo_multimap::value_type(-1,-1));" << endl;
  p = find(v1.begin(),v1.end(),tipo_multimap::value_type(-1,-1));

  if (p == v1.end())
    cout << " No se ha encontrado el elemento (-1 -1) " << endl;
  else
     for_each(p,v1.end(),imprimir_par);


  cout << "\n find_if" << endl;

  cout << "\n p = find_if(v1.begin(),v1.end(),segunda_componente_par);" << endl;
  p = find_if(v1.begin(),v1.end(),segunda_componente_par);

  cout << endl;

  if (p != v1.end())
  cout << "  El elemento que tiene la segunda componente par es:  (" 
       << (*p).first << "," << (*p).second << ")" << endl;


 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;

 v2.clear();
 for (int i = 0; i < 10; i++)
  v2.insert(tipo_multimap::value_type(i%2,i));


 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir_par);
 cout << endl;

  cout << "\n find_first_of" << endl;
  cout << "\n p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());" << endl;
  p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());

  if (p != v1.end())
   cout << " El primer elemento encontrado de la primera secuencia que aparece en la segunda es --> ("
         << (*p).first << ", " << (*p).second << ")" << endl;


  cout << "\n find_adjacent " << endl;

  v1.insert(tipo_multimap::value_type(0,0));

  cout << "\n   p = adjacent_find(v1.begin(),v1.end());" << endl;
  p = adjacent_find(v1.begin(),v1.end());

  if (p != v1.end())
   for_each(p,v1.end(),imprimir_par);

  cout << endl;



 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n BUSCAR EN SECUENCIAS ORDENADAS " << endl;

 v1.clear();
 for (int i = 0; i < 10; i++)
  v1.insert(tipo_multimap::value_type(i,i));

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;


 cout << "\n binary_search(v1.begin(),v1.end(),tipo_multimap::value_type(3,3)) " << endl;

  if (binary_search(v1.begin(),v1.end(),tipo_multimap::value_type(3,3)))
   cout << " El elemento (3,3) se encuentra en el contenedor " << endl;



  cout << "\n  p = lower_bound(v1.begin(),v1.end(),tipo_multimap::value_type(3,3)); " << endl;
  cout << "\n  p1 = upper_bound(v1.begin(),v1.end()tipo_multimap::value_type(3,3));" << endl; 

  p = lower_bound(v1.begin(),v1.end(),tipo_multimap::value_type(3,3));
  p1 = upper_bound(v1.begin(),v1.end(),tipo_multimap::value_type(3,3));

 cout << " Intervalo de elementos igual a 3 " << endl;
 for_each(p,p1,imprimir_par);
 cout << endl;


  cout << "\n Se define  par como objeto de la clase pair " << endl;
  pair <tipo_multimap::iterator,tipo_multimap::iterator> par; 

  cout << "\n  par = equal_range(v1.begin(),v1.end(),3); " << endl;
  par = equal_range(v1.begin(),v1.end(),tipo_multimap::value_type(3,3));

  cout << " Intervalo de elementos igual a (3,3) " << endl;
  for_each(par.first,par.second,imprimir_par);
  cout << endl;



  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n CONTAR" << endl;

 v1.clear();
 for (int i = 0; i < 10; i++)
  v1.insert(tipo_multimap::value_type(i/4,i/4));

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;

  cout << "\n Uso de count para contar las apariciones de (1,1) --> "  
       << count(v1.begin(),v1.end(),tipo_multimap::value_type(1,1)) 
       << " veces " << endl;

  cout << "\n Uso de count_if para contar las apariciones de elementos que tienen la segunda componente par --> "  
       << count_if(v1.begin(),v1.end(),segunda_componente_par) << " veces "
       << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n COMPARAR " << endl  ;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir_par);
 cout << endl;

 v2.clear();
 for (int i = 0; i < 10; i++)
  v2.insert(tipo_multimap::value_type(i,i%4));

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir_par);
 cout << endl;

   cout << "\n Uso de equal " << endl;
   cout << "\n equal(v1.begin(),v1.end(),v2.begin()) " << endl;

  if (equal(v1.begin(),v1.end(),v2.begin()))
   cout << " Los contenedores v1 y v2 son iguales " << endl;
  else
   cout << " Los contenedores v1 y v2 son diferentes " << endl;
 

  cout << "\n Uso de mismatch " << endl;
  par = mismatch(v1.begin(),v1.end(),v2.begin());
  
  cout << "\n Los contenedores v1 y v2 son diferentes " 
       << "\n En la misma posición  " 
       << "\n v1 tiene el elemento (" << par.first->first  << "," << par.first->second << ")"
       << "\n y v2 tiene el elemento (" << par.second->first  << "," << par.second->second << ")"
       << endl;

 cout << "\n Uso de lexicographical_compare " << endl;
  if (lexicographical_compare(v1.begin(),v1.end(),v2.begin(),v2.end()))
    cout << " v1 precede lexicográficamente a v2 ";
  else
    cout << " v2 precede lexicográficamente a v1 ";


///////////////////////////////////////////////////
 cout << "\n\n **************************************** \n" ;
 cout << "\n MAXIMO Y MINIMO " << endl ;

 p = max_element(v1.begin(),v1.end());
 p1 = min_element(v1.begin(),v1.end());

 cout << " máximo de v1 : (" << p->first  << "," << p->second << ")"
      << endl
      << " mínimo de v1 : (" << p1->first  << "," << p1->second << ")"
      << endl;


//////////////////////////////////////

 cout << "\n ************************************************** " << endl ;
 cout << "\n ************************************************** " << endl ;

 cout << "\n ALGORITMOS MODIFICADORES " << endl ;

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de swap " << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir_par);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir_par);
  cout << endl;

  cout << "Intercambiar v1 y v2 --> swap(v1,v2); " << endl;
  swap(v1,v2);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir_par);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir_par);
  cout << endl;



 // Salida normal del programa
 return 0;
}





////////////////////////////////

void imprimir_par (pair<int,int> dato)
{
  cout  << "(" << dato.first << "," << dato.second << ") " ;
}



bool segunda_componente_par ( pair <int, int> dato)
{
  return ( (dato.second % 2) == 0)? true:false ;
}


