/***********************************************************************************/
/******************************* EJERCICIO STL 1 C++ *******************************/
/***********************************************************************************
EXPLICACIÓN: STL es una parte de la biblioteca de C++ que permite declarar variables
con estructuras como tipo de datos (listas, vectores, pilas, etc.) y contiene todas
sus posibles operaciones (insertar, suprimir, etc.) ahorrando trabajo al programador
de hacer estructuras o clases manualmente que realicen estas operaciones.
    
Implementar una pila mediante STL e incluir un menú que permita realizar todas sus
operaciones.
             
/***********************************************************************************/
/******************************** LIBRERIAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#include <stack> //Para poder declarar una pila.
using namespace std;

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    stack<int> Pila; //Declaramos Pila como una pila de enteros.
    int opcion, Elemento;
    
    while (opcion != 4){
          cout << "Opcion 1: Intertar un elemento en la pila." << endl;
          cout << "Opcion 2: Extraer un elemento de la pila." << endl;
          cout << "Opcion 3: Ver cabecero." << endl;
          cout << "Opcion 4: Salir del programa." << endl << endl;
          cout << "Elige una opcion: ";
          cin >> opcion;
          switch (opcion){
                 //Caso 1: Insertar Elemento.
                 case 1:
                      cout << endl << "Introduzca elemento: ";
                      cin >> Elemento;
                      Pila.push(Elemento); //Insertamos un elemento.
                      cout << endl << "Elemento insertado." << endl;
                      getchar();
                      getchar();
                 break;
                 //Caso 2: Extraer Elemento.
                 case 2:
                      if (Pila.empty()){ //Si la pila está vacía.
                             cout << endl << "No se pueden extraer elementos porque la pila esta vacia." << endl;
                      }
                      else{
                           cout << endl << "Elemento [" << Pila.top() << "] extraido." << endl;
                           Pila.pop(); //Extraemos el elemento de arriba.
                      }  
                      getchar();
                      getchar();
                 break;
                 //Caso 3: Ver Cabecero.
                 case 3:
                      if (Pila.empty()){
                             cout << endl << "La pila esta vacia." << endl;
                      }
                      else{
                           cout << endl << "El cabecero es: [" << Pila.top() << "]." << endl; //Mostramos el cabecero.
                      }  
                      getchar();
                      getchar();
                 break;
                 //Caso 4: Salir
                 case 4:
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
