/***********************************************************************************/
/******************************* EJERCICIO STL 2 C++ *******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/*********************************************************************************** 
Implementar un vector mediante STL e incluir un menú que permita realizar operaciones.
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#include <vector> //Para poder declarar un vector.
using namespace std;

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    vector<int> Vector; //Declaramos Vector como un vector de enteros.
    int opcion, Elemento, i;
    
    while (opcion != 7){
          cout << "Opcion 1: Insertar un elemento al principio del vector." << endl;
          cout << "Opcion 2: Intertar un elemento al final del vector." << endl;
          cout << "Opcion 3: Eliminar el primer elemento del vector." << endl;
          cout << "Opcion 4: Eliminar el ultimo elemento del vector." << endl;
          cout << "Opcion 5: Mostrar los elementos del vector." << endl;
          cout << "Opcion 6: Eliminar todos los elementos del vector." << endl;
          cout << "Opcion 7: Salir del programa." << endl << endl;
          cout << "Elige una opcion: ";
          cin >> opcion;
          switch (opcion){
                 //Caso 1: Insertar Elemento al principio.
                 case 1:
                      cout << endl << "Introduzca elemento: ";
                      cin >> Elemento;
                      Vector.insert (Vector.begin(), Elemento); //Insertamos el elemento por el principio.
                      cout << endl << "Elemento insertado." << endl;
                      getchar();
                      getchar();
                 break;
                 //Caso 2: Insertar elemento al final.
                 case 2:                      
                      cout << endl << "Introduzca elemento: ";
                      cin >> Elemento;
                      Vector.push_back(Elemento); //Insertamos un elemento al final. También podría haber sido Vector.insert (Vector.end(), Elemento)
                      cout << endl << "Elemento insertado." << endl;
                      getchar();
                      getchar();                      
                 break;
                 //Caso 3: Eliminar el primer elemento.
                 case 3:
                      if (Vector.empty()){ 
                             cout << endl << "No se pueden eliminar elementos porque el vector esta vacio." << endl;
                      }
                      else{
                           cout << endl << "Elemento [" << Vector.front() << "] extraido." << endl; //Mostramos el primer elemento.
                           Vector.erase(Vector.begin());  //Borramos el primer elemento.
                      }  
                      getchar();
                      getchar();
                 break;
                 //Caso 4: Eliminar el último elemento.
                 case 4:
                      if (Vector.empty()){ 
                             cout << endl << "No se pueden eliminar elementos porque el vector esta vacio." << endl;
                      }
                      else{
                           cout << endl << "Elemento [" << Vector.back() << "] extraido." << endl; //Mostramos el último elemento.
                           Vector.pop_back();  //Borramos el último elemento.
                      }  
                      getchar();
                      getchar();                      
                 break;       
                 //Caso 5: Mostrar los elementos del vector.
                 case 5:                      
                      if (Vector.empty()){ //Si el vector está vacío.
                             cout << endl << "El vector esta vacio." << endl;
                      }
                      else{
                           cout << endl << "Los elementos del vector son: ";
                           for (i=0; i<Vector.size(); i++){ //Vector.size() nos dice los elementos que tiene vector.
                               cout << "[" << Vector[i] << "] ";
                           }
                           cout << endl;
                      }  
                      getchar();
                      getchar();
                 break;
                 //Caso 6: Vaciar vector.
                 case 6:
                      Vector.clear();
                      cout << endl << "Vector limpio." << endl;
                      getchar();
                      getchar();
                 break;
                 //Caso 6: Salir                 
                 case 7:
                 break;                 
                 //Caso cualquiera: Mostrar error.
                 default:
                         cout << endl << "Opcion invalida, vuelve a intentarlo." << endl;
                         getchar();
                         getchar();
                 break;                   
          }
    }
}
