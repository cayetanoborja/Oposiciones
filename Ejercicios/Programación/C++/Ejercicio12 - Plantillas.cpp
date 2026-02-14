/***********************************************************************************/
/**************************** EJERCICIO PLANTILLAS 1 C++ ***************************/
/***********************************************************************************
EXPLICACIÓN: A veces se quiere implementar varias clases totalmente idénticas excepto
por el tipo de datos que manejan (por ejemplo, una cola de enteros, de caracteres, etc).
Se podrían escribir tantas veces como clases se quieran manejar o se podría escribir
una clase genérica que acepte cualquier valor, a esto se le llama plantilla.
    
Una cola es una clase de tipo FIFO, es decir, que el primer elemento será el último
en salir y el último en entrar es el primero en salir. Piensa en una pila de platos.
Implementar una clase pila de tipo genérico. Posteriormente se mostrará un menú que
permita elegir entre que tipo de pila se quiere operar (enteros o caracteres) y mostrar
otro menú que permita realizar operaciones sobre la pila.
             
/***********************************************************************************/
/******************************** LIBRERIAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#define TamanoMaxPila 100
using namespace std;

//CLASE COLA.
template <typename T> //Creamos la plantilla con el tipo de datos genérico T. Más tarde se defenirá que tipo de datos será T.
class Pila{
      //Atributos.
      private:
              T *Elemento; //Elemento será un puntero que apunte a un tipo T.
              int TamMaxPila;
              int PosCabecero;
      //Métodos.
      public:
              //Constructor.
              Pila (){
                   TamMaxPila = TamanoMaxPila;
                   PosCabecero = -1;
                   Elemento = new (nothrow) T[TamMaxPila]; //Inicializamos el puntero como un puntero a un vector de T (enteros, caracteres,...). 
              }
              //Destructor.
              ~Pila (){
                    delete[] Elemento;
              }
              //Método devoluciçon de PosCabecero
              int getPosCabecero(){
                  return PosCabecero;
              }
              //Método que devuelve el cabecero.
              T getCabecero(){
                  return Elemento[PosCabecero];
              }
              //Método que extrae un elemento de la cola. (Pop)
              T Pop(){
                  PosCabecero--;
                  return Elemento[PosCabecero + 1];
              }
              //Método que introduce un elemento en la cola. (Push).
              void Push (const T &Valor){
                   ++PosCabecero;
                   Elemento[PosCabecero] = Valor;
              }
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    Pila<int> PilaEnteros; //Creamos una pila de enteros.
    Pila<string> PilaCaracteres; //Creamos una pila de caracteres. 
    //Las plantillas son útiles para el programador, pero cuando el programa se compila en realidad almacenará 2 pilas, una para cada tipo de datos, por lo que para el ordenador, en realidad, es lo mismo que escribir 2 pilas.
    int opcion;  
    int TipodePilaEscogido; //Para saber que tipo se escoge.
    int ElementoEnteros;
    string ElementoCaracteres;

    while ((opcion != 1) && (opcion != 2)){
          cout << "Opcion 1: Crear pila de enteros." << endl;
          cout << "Opcion 2: Crear pila de caracteres." << endl << endl;
          cout << "Elige una opcion: ";
          cin >> opcion;
          switch (opcion){
                 case 1:
                      system ("cls");
                      cout << "******** COLA DE ENTEROS *******" << endl << endl;
                      TipodePilaEscogido = 1;
                 break;
                 case 2:
                      system ("cls");
                      cout << "****** COLA DE CARACTERES ******" << endl << endl;
                      TipodePilaEscogido = 2;
                 break;
                 default:
                         cout << endl << "Opcion invalida, vuelve a intentarlo." << endl;
                         getchar();
                         getchar();
                 break;  
          }  
    }
    opcion = 0;
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
                      if (TipodePilaEscogido == 1){ //Escogimos enteros.
                             cout << endl << "Introduzca elemento: ";
                             cin >> ElementoEnteros;
                             PilaEnteros.Push(ElementoEnteros);
                      }
                      else{ //Se escogió de caracteres.
                             cout << endl << "Introduzca elemento: ";
                             cin >> ElementoCaracteres;
                             PilaCaracteres.Push(ElementoCaracteres);                             
                      }
                      cout << endl << "Elemento insertado." << endl;
                      getchar();
                      getchar();
                 break;
                 //Caso 2: Extraer Elemento.
                 case 2:
                      if (TipodePilaEscogido == 1){ //Escogimos enteros.
                             if (PilaEnteros.getPosCabecero() == -1){
                                  cout << endl << "No se pueden extraer elementos porque la pila esta vacia." << endl;
                             }
                             else{
                                  cout << endl << "Elemento [" << PilaEnteros.Pop() << "] extraido." << endl;
                             }
                      }
                      else{ //Se escogió de caracteres.
                             if (PilaCaracteres.getPosCabecero() == -1){
                                  cout << endl << "No se pueden extraer elementos porque la pila esta vacia." << endl;
                             }
                             else{
                                  cout << endl << "Elemento [" << PilaCaracteres.Pop() << "] extraido." << endl;
                             }                          
                      }
                      getchar();
                      getchar();
                 break;
                 //Caso 3: Ver Cabecero.
                 case 3:
                      if (TipodePilaEscogido == 1){ //Escogimos enteros.
                             if (PilaEnteros.getPosCabecero() == -1){
                                  cout << endl << "La pila esta vacia." << endl;
                             }
                             else{
                                  cout << endl << "El cabecero es: [" << PilaEnteros.getCabecero() << "]." << endl;
                             }
                      }
                      else{ //Se escogió de caracteres.
                             if (PilaCaracteres.getPosCabecero() == -1){
                                  cout << endl << "La pila esta vacia." << endl;
                             }
                             else{
                                  cout << endl << "El cabecero es [" << PilaCaracteres.getCabecero() << "]." << endl;
                             }                          
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
