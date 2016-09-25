
/////////////////////////////////
///
/// ejemplo_deque.cpp
///
///////////////////////////////////

#include <iostream>
#include <deque>

#include <algorithm>


#include <numeric>

using namespace std;

///

int producto(int a, int b);
void imprimir (int dato);
bool impar (int dato);
int azar();
bool segunda_componente_par ( pair <int, int> dato);
int doble(int a);

int main()
{

 deque <int> v1;
 deque <int> v2;
 deque <double> w1(10);

  if (v1.empty())
    cout << "El deque v1 está vacío" << endl;
  else
    cout << "El deque v1 no está vacío" << endl;


  if (w1.empty())
    cout << "El deque w1 está vacío" << endl;
  else
    cout << "El deque w1 no está vacío" << endl;
 

  cout << "La longitud máxima del deque de enteros v1 es: " << v1.max_size() << endl;

  cout << "La longitud máxima del deque de reales w1 es: " << w1.max_size() << endl;


  cout << "La longitud actual del deque de enteros v1 es: " << v1.size() << endl;

  cout << "La longitud actual del deque de reales w1 es: " << w1.size() << endl;

  v1.resize(5);

  cout << "La longitud actual del deque de enteros v1 es: " << v1.size() << endl;



  cout << "La longitud actual del deque de enteros v2 es: " << v2.size() << endl;

  v2 = v1;

  cout << "La longitud actual del deque de enteros v2 es: " << v2.size() << endl;

  v2.resize(7);

 cout << "La longitud actual del deque de enteros v2 es: " << v2.size() << endl; 

  for(int i = 0; i < v1.size(); i++)
    v1[i] = -i;
   
  for(int i = 0; i < v2.size(); i++)
    v2[i] = i;
  
 for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

 for(int i = 0; i < v2.size(); i++)
    cout << " v2[" << i << "] = " << v2[i] << " ";

  cout << endl;

  v1.swap(v2);

 for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

 for(int i = 0; i < v2.size(); i++)
    cout << " v2[" << i << "] = " << v2[i] << " ";

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



   /// Acceso a elementos
  
   cout << "\n ************************************* \n" ;
   cout << "\n Acceso a elementos " << endl;
   cout << " v1.front() = " << v1.front() << endl; 
   cout << " v1.back() = " << v1.back() << endl; 
   cout << " v1[2] = " << v1[2] << endl; 
   cout << " v1.at(2) = " << v1.at(2) << endl; 

   for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
   cout << endl;



///////////////////////////////////////////////

 cout << "\n ************************************* \n" ;
  cout << "\n assign " << endl;

  v1.resize(10);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = 10-i;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n v2.assign(v1.begin(),v1.end()); " << endl;
  v2.assign(v1.begin(),v1.end());

  cout << " v2 "; 
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;



 /// Uso de iteradores

  cout << "\n ************************************* \n" ;
  cout << "\n Iteradores " << endl;
  

  cout << "\n iterator " << endl;

  deque<int>::iterator p;
  int i = 0;

  for(p = v1.begin(); p < v1.end(); p++)
     *p = 10 * i++;

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;


  cout << "\n reverse_iterator " << endl;
  i = 0;
  deque<int>::reverse_iterator q;

  for(q = v1.rbegin(); q < v1.rend(); q++)
     *q = 20 * i++ ;

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  cout << "\n Aritmética " << endl;
  p = v1.begin();

  cout << " Contenido de p: " << *p <<  endl;
  cout << " Contenido de p++: " << *(p++) << endl;
  cout << " Contenido de ++p: " << *(++p) <<  endl;
  cout << " Contenido de p--: " << *(p--) << endl;
  cout << " Contenido de --p: " << *(--p) <<  endl;
  
  deque<int>::iterator p1;
  cout << " p1 = p " <<  endl;
  p1 = p;
  cout << " Contenido de p1: " << *p1 <<  endl;

  if (p == p1) 
   cout << " p == p1 " << endl;

  if (p != p1) 
   cout << " p != p1 " << endl;

  if (p < p1) 
   cout << " p < p1 " << endl;

  if (p <= p1) 
   cout << " p <= p1 " << endl;

  if (p > p1) 
   cout << " p > p1 " << endl;

  if (p >= p1) 
   cout << " p >= p1 " << endl;


  cout << "\n Contenido de *p: " << *p <<  endl;
  p += 3;
  cout << " p += 3 --> Contenido de *p: " << *p <<  endl;

  p -= 2;
  cout << " p -= 2 --> Contenido de *p: " << *p <<  endl;

  cout << " Contenido de *(p + 1): " << *(p+1) <<  endl;
 
  cout << " Contenido de *(p - 1): " << *(p-1) <<  endl;

  cout << " Elemento p[0]: " << p[0] << " es igual a *p: " << *p << endl;
  cout << " Elemento p[3]: " << p[3] <<  endl;


  //////////////////////////////////////////////////////////////

  cout << "\n ************************************* \n" ;
  cout << "\n Borrar " << endl;

  p = v1.begin() + 2;

  cout << " Se va a borrar el elemento  p = v1.begin() + 2 --> " << *p << endl;
 
  v1.erase(p);

   for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  cout << " Se borran todos los elementos de v1 con  v1.erase(v1.begin(),v1.end());" << endl;
  
  v1.erase(v1.begin(),v1.end());

  cout << " La longitud actual del deque de enteros v1 es: " << v1.size() << endl;

  cout << " Se borran todos los elementos de v2 con  v2.clear();" << endl;
  v2.clear();

  cout << " La longitud actual del deque de enteros v2 es: " << v2.size() << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;
  cout << "\n Añadir y quitar elementos por el final " << endl;

  cout << " Uso de v1.push_back(10); v1.push_back(20); v1.push_back(30); \n"; 
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);



  cout << " Uso de v1.push_front(90);); \n"; 
  v1.push_front(10);

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  cout << " Uso de v1.pop_back() \n"; 
  v1.pop_back();

  cout << " Uso de v1.pop_front() \n"; 
  v1.pop_front();

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;



  //////////////////////////////////////////////////////////////


  cout << "\n **************************************** \n" ;

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;


  cout << "\n v1.insert(v1.begin(), 0); " << endl;
  v1.insert(v1.begin(), 0);

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  cout << "\n v2.insert(v2.begin(),5,-1); " << endl;
  v2.insert(v2.begin(),5,-1);

  for(int i = 0; i < v2.size(); i++)
    cout << " v2[" << i << "] = " << v2[i] << " ";
  cout << endl;

  cout << "\n v1.insert(v1.begin(),v2.begin(),v2.end()); " << endl;
  v1.insert(v1.begin(),v2.begin(),v2.end());

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

 for(int i = 0; i < v1.size(); i++)
    v1[i] = i;

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
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

  if (p >= v1.end())
    cout << " No se ha encontrado el elemento -1 " << endl;
  else
     for_each(p,v1.end(),imprimir);

  cout << "\n find_if" << endl;

  cout << "\n p = find_if(v1.begin(),v1.end(),impar);" << endl;
  p = find_if(v1.begin(),v1.end(),impar);

  cout << endl;

  if (p >=  v1.begin() && p < v1.end())
   cout << " El elemento impar encontrado es --> " << *p << endl  << endl;


  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  for(int i = 0; i < v2.size(); i++)
    v2[i] = v2.size()- i;

 for(int i = 0; i < v2.size(); i++)
    cout << " v2[" << i << "] = " << v2[i] << " ";
  cout << endl;

  cout << "\n find_first_of" << endl;
  cout << "\n p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());" << endl;
  p = find_first_of(v1.begin(),v1.end(),v2.begin(),v2.end());

  if (p >=  v1.begin() && p < v1.end())
   cout << " El primer elemento encontrado de la primera secuencia que aparece en la segunda es --> " << *p << endl;


  cout << "\n find_adjacent" << endl;

  cout << " Se modifica el valor del v1[2] para que coincida con v1[3] " << endl;
  v1[2] = v1[3];

  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
  cout << endl;

  cout << "\n   p = adjacent_find(v1.begin(),v1.end());" << endl;
  p = adjacent_find(v1.begin(),v1.end());

  if (p >=  v1.begin() && p < v1.end())
   for_each(p,v1.end(),imprimir);

  cout << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n BUSCAR EN SECUENCIAS ORDENADAS " ;


  for(int i = 0; i < v1.size(); i++)
    cout << " v1[" << i << "] = " << v1[i] << " ";
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
  pair <deque<int>::iterator,deque<int>::iterator> par; 

  cout << "\n  par = equal_range(v1.begin(),v1.end(),3); " << endl;
  par = equal_range(v1.begin(),v1.end(),3);

  cout << " Intervalo de elementos igual a 3 " << endl;
  for_each(par.first,par.second,imprimir);
  cout << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n CONTAR" ;

  cout << "\n Uso de count para contar las apariciones de 3 --> "  << count(v1.begin(),v1.end(),3) << " veces " << endl;

  cout << "\n Uso de count_if para contar las apariciones de impares --> "  
       << count_if(v1.begin(),v1.end(),impar) << " veces "
       << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n COMPARAR " ;

   cout << "\n Uso de equal " << endl;
   cout << "\n equal(v1.begin(),v1.end(),v2.begin()) " << endl;

  if (equal(v1.begin(),v1.end(),v2.begin()))
   cout << " Los contenedores v1 y v2 son iguales " << endl;
  else
   cout << " Los contenedores v1 y v2 son diferentes " << endl;
 

  cout << "\n Uso de mismatch " << endl;
  par = mismatch(v1.begin(),v1.end(),v2.begin());
  
  cout << "\n Los contenedores v1 y v2 son diferentes " 
       << "\n En la posición " << (par.first - v1.begin())
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

  v1.resize(20);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%10;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  for(int i = 0; i < v2.size(); i++)
    v2[i] = i + 3;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n Uso de search para comprobar si v2 es un subsecuencia de v1 " << endl ;

  p = search(v1.begin(),v1.end(),v2.begin(),v2.end());

  if ((p >= v1.begin()) && (p < v1.end()))
   {
     cout << " Se imprimen los elementos de v1 a partir de la primera aparición de la subsecuencia v2  " << endl; 
     for_each(p,v1.end(),imprimir);

     cout << endl;
   }

 /////////////////////////////////////////////

  cout << "\n Uso de find_end para comprobar si v2 es un subsecuencia de v1 " << endl ;

  p = find_end(v1.begin(),v1.end(),v2.begin(),v2.end());

  if ((p >= v1.begin()) && (p < v1.end()))
   {
     cout << " Se imprimen los elementos de v1 a partir de la última aparición de la subsecuencia v2 " << endl; 
     for_each(p,v1.end(),imprimir);

     cout << endl;
   }

  cout << endl;

 ///////////////////////////

  for(int i = 7; i < v1.size()-7; i++)
    v1[i] = 5;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Uso de search_n para comprobar si el valor 5 aparece 3 o más veces seguidas en v1 " << endl ;

  p = search_n(v1.begin(),v1.end(),3,5);

  if ((p >= v1.begin()) && (p < v1.end()))
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

 v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i;

 v2.resize(5);
  for(int i = 0; i < v2.size(); i++)
    v2[i] = -i;
  
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de copy" << endl;

  cout << " Copia v1 en v2 --> copy(v1.begin(),v1.end(),v2.begin()); " << endl;
  copy(v1.begin(),v1.end(),v2.begin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

 /////////////////////

 cout << "\n ***************************** " << endl ;

  cout << "\n Uso de copy_backward" << endl;

 v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i;

 v2.resize(10);
  for(int i = 0; i < v2.size(); i++)
    v2[i] = -i;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << " Copia v1 desde el final de v2  hacia atrás --> copy_backward(v1.begin(),v1.end(),v2.end()); " << endl;
  copy_backward(v1.begin(),v1.end(),v2.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;



/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de fill " << endl;


  cout << " fill(v1.begin(),v1.end(),1); " << endl;
  fill(v1.begin(),v1.end(),1);


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de fill_n " << endl;


  cout << " fill_n(v1.begin(),3,2); " << endl;
  fill_n(v1.begin(),3,2);


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de generate " << endl;


  cout << " generate(v1.begin(),v1.end(),azar); " << endl;
  generate(v1.begin(),v1.end(),azar);


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de generate_n " << endl;


  cout << " generate_n(v1.begin(),3,azar); " << endl;
  generate_n(v1.begin(),3,azar);


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;



/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de swap " << endl;

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  v2.resize(5);
  for(int i = 0; i < v2.size(); i++)
    v2[i] = -(i+1);

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


  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de swap_ranges " << endl;

  cout << " Intercambiar los dos primeros elementos "
       << "\n --> swap_ranges(v1.begin(),v1.begin()+2,v2.begin()); " << endl;
  swap_ranges(v1.begin(),v1.begin()+2,v2.begin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de iter_swap " << endl;

  cout << " Intercambiar los últimos elementos de v1 y v2 "
       << "\n --> iter_swap(v1.rbegin(),v2.rbegin()); " << endl;
  iter_swap(v1.rbegin(),v2.rbegin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de partition " << endl;

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " Se colocan delante los impares --> partition(v1.begin(),v1.end(),impar);" << endl;
  partition(v1.begin(),v1.end(),impar);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;




/////////////////////

  cout << "\n ***************************** " << endl ;
  cout << "\n Uso de stable_partition " << endl;

  
  deque <pair <int, int> > puntos(10);  

  for(int i = 0; i < puntos.size(); i++)
   {
    puntos[i].first = i+1;
    puntos[i].second = i%2;
   }

  cout << " puntos ";
  
  for(int i = 0; i < puntos.size(); i++)
   {
     cout << "\n (" << puntos[i].first << ", " << puntos[i].second << ") ";
   }

  cout << endl;


  cout << "\n Se colocan delante los que tienen la segunda componente par (respetando el orden relativo) "
       << "\n --> stable_partition(puntos.begin(),puntos.end(),segunda_componente_par)"
       << endl;

  stable_partition(puntos.begin(),puntos.end(),segunda_componente_par);

  for(int i = 0; i < puntos.size(); i++)
   {
     cout << "\n (" << puntos[i].first << ", " << puntos[i].second << ") ";
   }

   cout << endl;




/////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n PERMUTACIONES " << endl;

  cout << "\n Uso de random_shuffle " << endl;

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << " Permutación aleatoria " << endl;
  random_shuffle(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  if (next_permutation(v1.begin(),v1.end()))
   {
    cout << "\n Existe una permutación lexicográficamente posterior " << endl;
 
    cout << " v1 ";
    for_each(v1.begin(),v1.end(),imprimir);
    cout << endl;
   }
  else
   cout << "\n No Existe una permutación lexicográficamente posterior " << endl;

 
  if (prev_permutation(v1.begin(),v1.end()))
   {
    cout << "\n Existe una permutación lexicográficamente anterior " << endl;
 
    cout << " v1 ";
    for_each(v1.begin(),v1.end(),imprimir);
    cout << endl;
   }
  else
   cout << "\n No Existe una permutación lexicográficamente anterior " << endl;


/////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n BORRAR " << endl;

  v1.resize(10);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%2;

  cout << " v1.size()--> " << v1.size() << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se intenta borrar los elementos con valor igual a 1 " << endl;
  cout << "\n remove << no >> funciona correctamente con dequees" << endl;

  cout << "\n remove(v1.begin(),v1.end(),1); " << endl;
  remove(v1.begin(),v1.end(),1);

  cout << " El tamaño no cambia v1.size()--> " << v1.size() << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i;
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  for(int i = 0; i < v2.size(); i++)
    v2[i] = 9;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n Se copian en v2 los elementos de v1 que no son iguales a 3 " << endl;
  cout << "\n remove_copy(v1.begin(),v1.end(),v2.begin(),3); " << endl;

  remove_copy(v1.begin(),v1.end(),v2.begin(),3);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;



 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i;
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  for(int i = 0; i < v2.size(); i++)
    v2[i] = 9;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n Se copian en v2 los elementos de v1 que no son impares " << endl;
  cout << "\n remove_copy_if(v1.begin(),v1.end(),v2.begin(),impar); " << endl;

  remove_copy_if(v1.begin(),v1.end(),v2.begin(),impar);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i;
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n Se borran de v1 los elementos que son impares " << endl;
  cout << "\n remove_if(v1.begin(),v1.end(),impar) " << endl;

  remove_if(v1.begin(),v1.end(),impar);

  cout << "\n remove_if << no >> funciona correctamente con dequees" << endl;
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


 //////////////////////////////////////////////////////

 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i/2;
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n Se borran de v1 los elementos adyacentes duplicados  " << endl;
  cout << "\n unique(v1.begin(),v1.end()); " << endl;

  unique(v1.begin(),v1.end());

  cout << "\n unique << no >> funciona correctamente con dequees" << endl;
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl; 


  cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i/2;
 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n Realiza una copia de v1 en v2 sin duplicados " << endl;
  cout << "\n unique_copy(v1.begin(),v1.end(),v2.begin()); " << endl;

  unique_copy(v1.begin(),v1.end(),v2.begin());

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl; 

//////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n SUSTITUIR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%2;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se sustituyen los elementos de v1 que valgan 1 por 9 " << endl;

  cout << "\n  replace(v1.begin(),v1.end(),1,9); " << endl;
  replace(v1.begin(),v1.end(),1,9);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

 cout << "\n ***************************** " << endl ;

 for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se sustituyen los elementos de v1 que sean impares por 0 " << endl;

  cout << "\n  replace_if(v1.begin(),v1.end(),impar,0); " << endl;
  replace_if(v1.begin(),v1.end(),impar,0);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%2;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(v1.size());

  cout << "\n Se sustituyen los elementos de v1 que valgan 1 por 9 y los copia en v2 " << endl;

  cout << "\n replace_copy(v1.begin(),v1.end(),v2.begin(),1,9); " << endl;
  replace_copy(v1.begin(),v1.end(),v2.begin(),1,9);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


 cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se sustituyen los elementos de v1 que sean impares por el valor 0 y los copia en v2 " << endl;

  cout << "\n replace_copy_if(v1.begin(),v1.end(),v2.begin(),impar,0); " << endl;
  replace_copy_if(v1.begin(),v1.end(),v2.begin(),impar,0);

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


 /////////////////////////////////////////////////////


 cout << "\n ***************************** " << endl ;
 
  cout << "\n TRANSFORMAR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se transforman los elementos de v1 y se copian en v2 " << endl;

  cout << "\n transform(v1.begin(),v1.end(),v2.begin(),doble); " << endl;
  transform(v1.begin(),v1.end(),v2.begin(),doble);

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;



//////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n INVERTIR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se invierten los elementos de v1 " << endl;

  cout << "\n  reverse(v1.begin(),v1.end()); " << endl;
  reverse(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;



  cout << "\n ***************************** " << endl ;
 
  cout << "\n INVERTIR Y COPIAR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se invierten los elementos de v1 y se copian en v2 " << endl;

  cout << "\n reverse_copy(v1.begin(),v1.end(),v2.begin()); " << endl;
  reverse_copy(v1.begin(),v1.end(),v2.begin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


//////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n ROTAR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se rotan 2 puestos los elementos de v1 " << endl;

  cout << "\n  rotate(v1.begin(),v1.begin()+2,v1.end()); " << endl;
  rotate(v1.begin(),v1.begin()+2,v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n ***************************** " << endl ;
 
  cout << "\n ROTAR Y COPIAR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se rotan 2 puestos los elementos de v1 y se copian en v2 " << endl;

  cout << "\n rotate_copy(v1.begin(),v1.begin()+2,v1.end(),v2.begin()); " << endl;
  rotate_copy(v1.begin(),v1.begin()+2,v1.end(),v2.begin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


//////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  cout << "\n ORDENAR " << endl;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  random_shuffle(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se ordenan los elementos de v1 " << endl;

  cout << "\n  sort(v1.begin(),v1.end()); " << endl;
  sort(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


/////////////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%3;

  cout << "\n Uso de stable_sort " << endl;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Se ordenan los elementos de v1 respetando el orden relativo " << endl;

  cout << "\n  stable_sort(v1.begin(),v1.end()); " << endl;
  stable_sort(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;




/////////////////////////////////////////////////////////////

  cout << "\n ***************************** " << endl ;
 
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  random_shuffle(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << "\n Uso de partial_sort " << endl;

  cout << "\n Sólo garantiza la ordenación de los 4 primeros elementos de v1 " << endl;

  cout << "\n  partial_sort(v1.begin(),v1.end()); " << endl;
  partial_sort(v1.begin(),v1.begin()+4,v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


/////////////////////////////////////////////////////////////


  cout << "\n ***************************** " << endl ;
 
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  random_shuffle(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  cout << "\n Uso de partial_sort_copy " << endl;

  cout << "\n Sólo garantiza la ordenación de los 5 primeros elementos de v1 y el resultado lo copia en v2" << endl;

  cout << "\n   partial_sort_copy(v1.begin(),v1.end(),v2.begin(),v2.end()); " << endl;
  partial_sort_copy(v1.begin(),v1.end(),v2.begin(),v2.end());


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;


/////////////////////////////////////////////////////////////


  cout << "\n ***************************** " << endl ;
 
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  random_shuffle(v1.begin(),v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Uso de nth_element " << endl;

  cout << "\n Se garantiza que el noveno elemento está en el lugar que le correspondería si v1 estuviera ordenado" << endl;

  cout << "\n nth_element(v1.begin(),v1.begin()+9,v1.end()); " << endl;
  nth_element(v1.begin(),v1.begin()+9,v1.end());


  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;



/////////////////////////////////////////////////////////////


  cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  v2.resize(5);
  for(int i = 0; i < v2.size(); i++)
    v2[i] = i+5;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;


  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << "\n Uso de merge" << endl;

  cout << "\n Fusión de v1 y v2: el resultado se almacena en v3 " << endl;

  deque <int> v3(v1.size()+v2.size());

  cout << "\n merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); " << endl;
  merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  cout << " v3 ";
  for_each(v3.begin(),v3.end(),imprimir);
  cout << endl;


/////////////////////////////////////////////////////////////


  cout << "\n ***************************** " << endl ;

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i%5;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Uso de inplace_merge" << endl;

  cout << "\n Se mezclan dos partes ordenadas de v1" << endl;

  cout << "\n inplace_merge(v1.begin(),v1.begin()+5,v1.end()); " << endl;
  inplace_merge(v1.begin(),v1.begin()+5,v1.end());

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;



/////////////////////////////////////////////////////////////

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

  cout << "\n Uso de includes" << endl;

  cout << "\n Se comprueba si v2 está contenida en v1" << endl;

  cout << "\n includes(v1.begin(),v1.end(),v2.begin(),v2.end()) " << endl;

  if (includes(v1.begin(),v1.end(),v2.begin(),v2.end()))
   cout << " v2 está incluida en v1";
  else
   cout << "v 2 no está incluida en v1";
 
  cout << endl;


  //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n Algoritmos numéricos " << endl << endl;

  v1.resize(5);

  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

 
  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  cout << "\n Acumular " << endl;
  
  cout << " accumulate(v1.begin(),v1.end()) suma --> " <<  accumulate(v1.begin(),v1.end(),0) << endl;

  cout << " accumulate(v1.begin(),v1.end(),1,producto) --> " <<  accumulate(v1.begin(),v1.end(),1,producto) << endl;


 //////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n inner_product " << endl << endl;

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  for(int i = 0; i < v2.size(); i++)
    v2[i] = 1;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;
  
  cout << " inner_product(v1.begin(),v1.end(),v2.begin(),0) --> " 
       <<  inner_product(v1.begin(),v1.end(),v2.begin(),0) << endl;



//////////////////////////////////////////////////////////////

  cout << "\n **************************************** \n" ;

  cout << "\n partial_sum " << endl << endl;

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  for(int i = 0; i < v2.size(); i++)
    v2[i] = 0;

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

  v1.resize(5);
  for(int i = 0; i < v1.size(); i++)
    v1[i] = i+1;

  cout << " v1 ";
  for_each(v1.begin(),v1.end(),imprimir);
  cout << endl;

  v2.resize(5);

  for(int i = 0; i < v2.size(); i++)
    v2[i] = 0;

  cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;
  
  cout << " adjacent_difference(v1.begin(),v1.end(),v2.begin());  " << endl;
  adjacent_difference(v1.begin(),v1.end(),v2.begin());

 cout << " v2 ";
  for_each(v2.begin(),v2.end(),imprimir);
  cout << endl;

  
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


bool impar (int dato)
{
  return ( (dato % 2) == 0)? false:true ;
}


int azar()
{
  return rand()%10+1;
}



bool segunda_componente_par ( pair <int, int> dato)
{
  return ( (dato.second % 2) == 0)? true:false ;
}


int doble(int a)
 { 
  return 2 * a ;
 }

