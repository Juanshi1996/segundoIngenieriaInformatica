
/////////////////////////////////
///
/// ejemplo_set_1.cpp
///
///////////////////////////////////

#include <iostream>
#include <set>

#include <algorithm>


#include <numeric>

using namespace std;

///

int producto(int a, int b);
void imprimir (int dato);
bool impar (int dato);
void imprimir_double (double dato);

int main()
{

 set <int> v1;
 set <int> v2;
 set <int> v3;

 set <double> w1;


 for (int i = 0; i < 10; i++)
  v1.insert(i+1);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

  if (v1.empty())
    cout << "El set v1 está vacío" << endl;
  else
    cout << "El set v1 no está vacío" << endl;


  if (w1.empty())
    cout << "El set w1 está vacío" << endl;
  else
    cout << "El set w1 no está vacío" << endl;


 for (int i = 0; i < 10; i++)
  w1.insert(i+1.5);

 cout << " w1 ";
 for_each(w1.begin(),w1.end(),imprimir_double);
 cout << endl;

 

  cout << "La longitud máxima del set de enteros v1 es: " << v1.max_size() << endl;

  cout << "La longitud máxima del set de reales w1 es: " << w1.max_size() << endl;


  cout << "La longitud actual del set de enteros v1 es: " << v1.size() << endl;

  cout << "La longitud actual del set de reales w1 es: " << w1.size() << endl;


  cout << "La longitud actual del set de enteros v2 es: " << v2.size() << endl;


  cout << "La longitud actual del set de enteros v2 es: " << v2.size() << endl;


 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

 for (int i = 0; i < 10; i++)
  v2.insert(10+i);

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir);
 cout << endl;

  v1.swap(v2);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;
 

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir);
 cout << endl;




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
  
//  cout << "\n iterator " << endl;

  set<int>::iterator p;

  for(p = v1.begin(); p !=v1.end(); p++)
     cout << *p << " " ;

  cout << endl;


  cout << "\n reverse_iterator " << endl;
 
  set<int>::reverse_iterator q;


  for(q = v1.rbegin(); q != v1.rend(); q++)
     cout << *q << " " ;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;


/////////////////////////////////////////////////////

  cout << "\n Aritmética " << endl;
  p = v1.begin();

  cout << " Contenido de p: " << *p <<  endl;
  cout << " Contenido de p++: " << *(p++) << endl;
  cout << " Contenido de ++p: " << *(++p) <<  endl;
  cout << " Contenido de p--: " << *(p--) << endl;
  cout << " Contenido de --p: " << *(--p) <<  endl;
  

  set<int>::iterator p1;
  cout << " p1 = p " <<  endl;
  p1 = p;
  cout << " Contenido de p1: " << *p1 <<  endl;

  if (p == p1) 
   cout << " p == p1 " << endl;

  if (p != p1) 
   cout << " p != p1 " << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n ************************************* \n" ;
  cout << "\n Borrar " << endl;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

   cout << "\n  v1.erase(12); " << endl;

   v1.erase(12);


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;



  p = v1.begin();
  p++;

  cout << "  p = v1.begin() y p++, se va a borrar el elemento *p --> " << *p << endl;
 
  v1.erase(p);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;


  cout << " Se borran todos los elementos de v1 con  v1.erase(v1.begin(),v1.end());" << endl;
  
  v1.erase(v1.begin(),v1.end());

  cout << " La longitud actual del set de enteros v1 es: " << v1.size() << endl;

  cout << " Se borran todos los elementos de v2 con  v2.clear();" << endl;
  v2.clear();

  cout << " La longitud actual del set de enteros v2 es: " << v2.size() << endl;


   //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

  cout << "\n v1.insert(v1.begin(), 0); " << endl;
  v1.insert(v1.begin(), 0);
 
 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;


 for (int i = 0; i < 10; i++)
  v2.insert(10+i);


 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir);
 cout << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

 v1.clear();
 for (int i = 0; i < 10; i++)
  v1.insert(i);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

  cout << "\n ALGORITMOS INVARIANTES \n";

  cout << " for_each e imprimir \n";
  cout << " for_each(v1.begin(),v1.end(),imprimir);" << endl;
  for_each(v1.begin(),v1.end(),imprimir);


  cout << "\n BUSCAR EN CONTENEDORES NO ORDENADOS \n";

  cout << "\n find" << endl;
  cout << "\n p = find(v1.begin(),v1.end(),3);" << endl;
  p = find(v1.begin(),v1.end(),3);

  cout << " for_each(p,v1.end(),imprimir);" << endl;
  for_each(p,v1.end(),imprimir);

  cout << "\n p = find(v1.begin(),v1.end(),-1);" << endl;
  p = find(v1.begin(),v1.end(),-1);

  if (p == v1.end())
    cout << " No se ha encontrado el elemento -1 " << endl;
  else
     for_each(p,v1.end(),imprimir);


  cout << "\n find_if" << endl;

  cout << "\n p = find_if(v1.begin(),v1.end(),impar);" << endl;
  p = find_if(v1.begin(),v1.end(),impar);

  cout << endl;

  if (p != v1.end())
   cout << " El elemento impar encontrado es --> " << *p << endl  << endl;


 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

 v2.clear();
 for (int i = 0; i < 10; i++)
  v2.insert(10-i);


 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir);
 cout << endl;

  cout << "\n find_first_of" << endl;
  cout << "\n p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());" << endl;
  p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());

  if (p != v1.end())
   cout << " El primer elemento encontrado de la primera secuencia que aparece en la segunda es --> " << *p << endl;

  cout << "\n find_adjacent (no tiene sentido con set)" << endl;

  cout << "\n   p = adjacent_find(v1.begin(),v1.end());" << endl;
  p = adjacent_find(v1.begin(),v1.end());

  if (p != v1.end())
   for_each(p,v1.end(),imprimir);

  cout << endl;



 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n BUSCAR EN SECUENCIAS ORDENADAS " ;

 v1.clear();
 for (int i = 0; i < 10; i++)
  v1.insert(i);

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;


 cout << "\n binary_search(v1.begin(),v1.end(),3) " << endl;

  if (binary_search(v1.begin(),v1.end(),3))
   cout << " El elemento 3 se encuentra en el contenedor " << endl;


  cout << "\n  p = lower_bound(v1.begin(),v1.end(),3); " << endl;
  cout << "\n  p1 = upper_bound(v1.begin(),v1.end(),3);" << endl; 

  p = lower_bound(v1.begin(),v1.end(),3);
  p1 = upper_bound(v1.begin(),v1.end(),3);

 cout << " Intervalo de elementos igual a 3 " << endl;
 for_each(p,p1,imprimir);
 cout << endl;

  cout << "\n Se define  par como objeto de la clase pair " << endl;
  pair <set<int>::iterator,set<int>::iterator> par; 

  cout << "\n  par = equal_range(v1.begin(),v1.end(),3); (No tiene sentido con set) " << endl;
  par = equal_range(v1.begin(),v1.end(),3);

  cout << " Intervalo de elementos igual a 3 " << endl;
  for_each(par.first,par.second,imprimir);
  cout << endl;



  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n CONTAR" ;

  cout << "\n Uso de count para contar las apariciones de 3 --> "  << count(v1.begin(),v1.end(),3) << " veces (como es obvio en set) " << endl;

  cout << "\n Uso de count_if para contar las apariciones de impares --> "  
       << count_if(v1.begin(),v1.end(),impar) << " veces "
       << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n COMPARAR " ;

 cout << " v1 ";
 for_each(v1.begin(),v1.end(),imprimir);
 cout << endl;

 cout << " v2 ";
 for_each(v2.begin(),v2.end(),imprimir);
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
       << "\n v1 tiene el elemento " << *par.first
       << "\n y v2 tiene el elemento " << *par.second
       << endl;



 cout << "\n Uso de lexicographical_compare " << endl;
  if (lexicographical_compare(v1.begin(),v1.end(),v2.begin(),v2.end()))
    cout << " v1 precede lexicográficamente a v2 ";
  else
    cout << " v2 precede lexicográficamente a v1 ";

  cout << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n BÚSQUEDA DE SUBSECUENCIAS " << endl ;

  v1.clear();
  for(int i = 0; i < 10; i++)
    v1.insert(i%10);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.clear();
  for(int i = 0; i < 5; i++)
    v2.insert(i+3);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n Uso de search para comprobar si v2 es un subsecuencia de v1 " << endl ;

  p = search(v1.begin(),v1.end(),v2.begin(),v2.end());

  if ((p != v1.end()))
   {
     cout << " Se imprimen los elementos de v1 a partir de la primera aparición de la subsecuencia v2  " << endl; 
     for_each(p,v1.end(),imprimir);

     cout << endl;
   }


 /////////////////////////////////////////////

  cout << "\n Uso de find_end para comprobar si v2 es un subsecuencia de v1 (en set, se comporta igual que search) " << endl ;

  p = find_end(v1.begin(),v1.end(),v2.begin(),v2.end());

  if ((p !=  v1.end()))
   {
     cout << " Se imprimen los elementos de v1 a partir de la última aparición de la subsecuencia v2 " << endl; 
     for_each(p,v1.end(),imprimir);

     cout << endl;
   }

  cout << endl;


 ///////////////////////////

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Uso de search_n para comprobar si el valor 5 aparece 3 o más veces seguidas en v1 (no tiene sentido en set) " << endl ;

  p = search_n(v1.begin(),v1.end(),3,5);

  if (p != v1.end())
   {
     cout << " Se imprimen los elementos de v1 a partir del lugar en el valor 5 aparece 3 o más veces seguidas " << endl; 
     for_each(p,v1.end(),imprimir);

     cout << endl;
   }


 //////////////////////////////////////

 cout << "\n MAXIMO Y MINIMO " << endl ;

 p = max_element(v1.begin(),v1.end());
 p1 = min_element(v1.begin(),v1.end());

 cout << " máximo de v1 : " << *p 
      << endl
      << " mínimo de v1 : " << *p1
      << endl;



//////////////////////////////////////


//////////////////////////////////////

 cout << "\n ************************************************** " << endl ;
 cout << "\n ************************************************** " << endl ;

 cout << "\n ALGORITMOS MODIFICADORES " << endl ;

  v1.clear();
  for(int i = 0; i < 5; i++)
    v1.insert(i);

  v2.clear();
  for(int i = 0; i < 5; i++)
    v2.insert(-i);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de swap " << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "Intercambiar v1 y v2 --> swap(v1,v2); " << endl;
  swap(v1,v2);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

/*


/////////////////////////////////////////////////////////////


  cout << "\n ***************************** " << endl ;

  cout << "\n OPERACIONES DE CONJUNTOS " << endl;

  v1.clear();
  for(int i = 0; i < 10; i++)
    v1.insert(i+1);

 
 cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  for(int i = 0; i < 10; i++)
     v2.insert(i+5);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  v3.clear();


  cout << "\n Uso de set_union" << endl;

  cout << "\n Se unen v1 y v2" << endl;

  cout << "\n set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); " << endl;
 


  set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  cout << " v3 ";
  for_each(v3.begin(),v3.end(),imprimir);
  cout << endl;




 cout << "\n ***************************** " << endl ;

  v1.clear();
  for(int i = 0; i < 10; i++)
    v1.insert(i+1);

 
 cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  for(int i = 0; i < 10; i++)
     v2.insert(i+5);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  v3.clear();

  cout << "\n Uso de set_intersection" << endl;

  cout << "\n Se insertectan v1 y v2" << endl;

  cout << "\n set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); " << endl;

  set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  cout << " v3 ";
  for_each(v3.begin(),v3.end(),imprimir);
  cout << endl;


 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  for(int i = 0; i < v2.size(); i++)
    v2[i] = i+5;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  v3.resize(max(v1.size(),v2.size()));

  cout << "\n Uso de set_difference" << endl;

  cout << "\n Se hace la diferencia v1 y v2" << endl;

  cout << "\n set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); " << endl;
  cout << "\n No funciona correctamente con setes " << endl;

  set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  cout << " v3 ";
  for_each(v3.begin(),v3.end(),imprimir);
  cout << endl;


 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  for(int i = 0; i < v2.size(); i++)
    v2[i] = i+5;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  v3.resize(max(v1.size(),v2.size()));

  cout << "\n Uso de set_difference" << endl;

  cout << "\n Se hace la diferencia simétrica de v1 y v2" << endl;

  cout << "\n set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); " << endl;
  cout << "\n No funciona correctamente con setes " << endl;

  set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  cout << " v3 ";
  for_each(v3.begin(),v3.end(),imprimir);
  cout << endl;


  cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  for(int i = 0; i < v2.size(); i++)
    v2[i] = i+5;



  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  v3.resize(max(v1.size(),v2.size()));
*/


v1.clear();
  for(int i = 0; i < 10; i++)
    v1.insert(i+1);

 
 cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  for(int i = 0; i < 10; i++)
     v2.insert(i+5);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


  cout << "\n Uso de includes" << endl;

  cout << "\n Se comprueba si v1 está contenida en v2" << endl;

  cout << "\n includes(v2.begin(),v2.end(),v1.begin(),v1.end()) " << endl;

  if (includes(v2.begin(),v2.end(),v1.begin(),v1.end()))
   cout << " v1 está incluida en v2";
  else
   cout << " v1 no está incluida en v2";
 
  cout << endl;




  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n Algoritmos numéricos " << endl << endl;
  v1.clear();
  for(int i = 0; i < 5; i++)
    v1.insert(i+1);
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Acumular " << endl;
  
  cout << " accumulate(v1.begin(),v1.end()) suma --> " <<  accumulate(v1.begin(),v1.end(),0) << endl;

  cout << " accumulate(v1.begin(),v1.end(),1,producto) --> " <<  accumulate(v1.begin(),v1.end(),1,producto) << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n inner_product " << endl << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  v2.clear();
  v2.insert(1);


  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;
  
  cout << " inner_product(v1.begin(),v1.end(),v2.begin(),0) --> " 
       <<  inner_product(v1.begin(),v1.end(),v2.begin(),0) << endl;


/*
//////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n partial_sum " << endl << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.clear();
  v2.insert(0);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;
  
  cout << " partial_sum(v1.begin(),v1.end(),v2.begin());  " << endl;
  partial_sum(v1.begin(),v1.end(),v2.begin());

 cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


//////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n adjacent_difference " << endl << endl;

  cout << "\n Algoritmos numéricos " << endl << endl;
  v1.clear();
  for(int i = 0; i < 5; i++)
    v1.insert(i+1);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.clear();
  v2.insert(0);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;
  
  cout << " adjacent_difference(v1.begin(),v1.end(),v2.begin());  " << endl;
  adjacent_difference(v1.begin(),v1.end(),v2.begin());

 cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

*/
 // Salida normal del programa
 return 0;
}





////////////////////////////////

int producto(int a, int b)
 { 
  return a * b;
 }


void imprimir (int dato)
{
  cout  << " " << dato ;
}

void imprimir_double (double dato)
{
  cout  << " " << dato ;
}


bool impar (int dato)
{
  return ( (dato % 2) == 0)? false:true ;
}


