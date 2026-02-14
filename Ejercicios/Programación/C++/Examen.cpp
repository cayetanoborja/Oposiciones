/***********************************************************************************/
/********************************* EJERCICIO EXAMEN ********************************/
/***************************** Cayetano Borja Carrillo *****************************/
/*********************************************************************************** 
Dada la siguiente definición para la interface de la clase "ListaEnlazada", defina
completamente (incluyendo los cuerpos de todas las funciones miembros) la clase
"ListaDoblementeEnlazada", que se obtendrá de esta por derivación.
       
       //Definición de los nodos de la lista.
       typedef struct Nodo{
               UnTipo info;  //Contenido útil de la lista.
               struct Nodo *siguiente;  //Puntero al siguiente elemento.
       }TipoBase;
       
       class Lista{
             private:
                     int cuantos;  //Número actual de elementos.
                     TipoBase *puntero;  //Puntero al primer elemento de la lista.
                     int limite;  //Número máximo de elementos de la lista.
             public:
                    Lista ();
                    Lista (TipoBase *unElemento);
                    int insertaElemento (TipoBase *unElemento, int posicion);
                    TipoBase *eliminaElemento (TipoBase *unElemento, int posicion);
                    TipoBase *obtenElemento (int posicion);
                    virtual void eliminaTodos ();
                    virtual int numeroElementos();  //Número de elementos actual.
                    int posicionElemento (TipoBase *unElemento);  //Devuelve la posición de un elemento.
                    ~Lista();
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#include <vector> //Para poder declarar un vector.
using namespace std;

//Definición de los nodos de la lista.
typedef int UnTipo;

typedef struct Nodo{
       UnTipo info;  //Contenido útil de la lista.
       struct Nodo *siguiente, *anterior;  //Puntero al siguiente elemento.
}TipoBase;
       
class Lista{
       private:
             int cuantos;  //Número actual de elementos.
             TipoBase *puntero;  //Puntero al primer elemento de la lista.
             int limite;  //Número máximo de elementos de la lista.
       public:
       Lista ();
       Lista (TipoBase *unElemento);
       int insertaElemento (TipoBase *unElemento, int posicion);
       TipoBase *eliminaElemento (TipoBase *unElemento, int posicion);
       TipoBase *obtenElemento (int posicion);
       virtual void eliminaTodos ();
       virtual int numeroElementos();  //Número de elementos actual.
       int posicionElemento (TipoBase *unElemento);  //Devuelve la posición de un elemento.
       ~Lista();
};

//Clase hija ListaDoblementeEnlazada.
class ListaDoblementeEnlazada : public Lista{
      public:
             ListaDoblementeEnlazada(){}
             int insertaElemento (TipoBase *unElemento, int posicion){
                 TipoBase *Puntero;

                 
                // Nuevo = (Nodo *)malloc(sizeof(Nodo));
                // (*Nuevo).ant = NULL;
                 
             }
      
};
/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    TipoBase *ListaDoblemente;
    TipoBase *Nuevo = new TipoBase;
    (*Nuevo).anterior = NULL;
    (*Nuevo).siguiente = NULL;
}
