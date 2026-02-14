/***********************************************************************************/
/****************** EJERCICIO TAD LISTAS DOBLEMENTE ENLAZADAS C ********************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Partiendo de las siguientes definiciones de Nodo y de Item, implementar las
siguientes funciones cuya declaración se especifica, para gestionar una
lista doblemente enlazada:
      
      typedef int Item;
      
      typedef struct unnodo{
              Item el;
              struct unnodo *sig, *ant;;
      }Nodo;
      
      //Inserta "dato" al principio de la lista
      void InsertaPrincipioLD (Nodo **Primero, Item dato);
      
      //Inicializa la lista "Primero" a vacia.
      void VaciaLD (Nodo **Primero);
      
      //Devuelve true si la lista está vacía. 
      int EsVaciaLD (Nodo *Primero); 
      
      //Introduce un número aleatorio de ítems (maximo 100) con valores aleatorios
      //al principio de la lista usando la función "InsertaListaPrincipioLD". 
      void GeneraPorElPrincipioLD (Nodo **Primero);
      
      //Recibe un puntero a una lista y un puntero "ant" que apunta al último nodo
      //de la lista, e inserta un nuevo nodo como último elemento de la lista doble.
      //Además de realizar la insercción debe actualizar convenientemente los
      //punteros "Primero y "Ant".
      void InsertarListaDespuesLD (Nodo **Primero, Nodo **ant, Item d);
      
      //Empleando la función "InsertaListaDespuesLD", genera un número aleatorio
      //de items (máximo 100) con valores aleatorios al final de la lista.
      void GeneraPorElFinalLD (Nodo **Primero);
      
      //Escribe los elementos de la lista.
      void EscribeLista (Nodo *Primero);
      
      void main (void){
           Nodo *Primero;
           GeneraPorElPrincipioLD(&Primero);
           EscribeLista(Primero);
      }
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1
#define false 0

//DEFINIMOS LA ESTRUCTURA.
typedef int Item;
      
typedef struct unnodo{
        Item el;
        struct unnodo *sig, *ant;;
}Nodo;
      
//Inserta "dato" al principio de la lista
void InsertaPrincipioLD (Nodo **Primero, Item dato);
      
//Inicializa la lista "Primero" a vacia.
void VaciaLD (Nodo **Primero);
      
//Devuelve true si la lista está vacía. 
int EsVaciaLD (Nodo *Primero);

int EstaCreadaLD (Nodo *Primero); 
      
/*Introduce un número aleatorio de ítems (maximo 100) con valores aleatorios
al principio de la lista usando la función "InsertaListaPrincipioLD". */
void GeneraPorElPrincipioLD (Nodo **Primero);
      
/*Recibe un puntero a una lista y un puntero "ant" que apunta al último nodo
de la lista, e inserta un nuevo nodo como último elemento de la lista doble.
Además de realizar la insercción debe actualizar convenientemente los
punteros "Primero y "Ant".*/
void InsertaListaDespuesLD (Nodo **Primero, Nodo **ant, Item d);
      
/*Empleando la función "InsertaListaDespuesLD", genera un número aleatorio
de items (máximo 100) con valores aleatorios al final de la lista.*/
void GeneraPorElFinalLD (Nodo **Primero);

//Este no lo pide pero hace falta para "GeneraPorElFinalLD".
void CalcularAnt (Nodo *Primero, Nodo **ant);
           
//Escribe los elementos de la lista.
void EscribeLista (Nodo *Primero);

//EMPEZAMOS EL PROGRAMA, ESTO NO LO PIDE, SOLO SE HA HECHO PARA COMPROBAR DATOS.      
int main (){
     srand (time(NULL));
     Nodo *Primero;
     int opcion, Creada = 0;
     Item dato;
     
     while (opcion != 8){
           printf ("\n EJERCICIO LISTA DOBLEMENTE ENLAZADA.\n");
           printf ("\n Opcion 1: Crear la lista.");
           printf ("\n Opcion 2: Comprobar si la lista esta vacia.");
           printf ("\n Opcion 3: Insertar un dato en el principio de la Lista.");
           printf ("\n Opcion 4: Introduce un numero aleatorio de Items por el principio.");
           printf ("\n Opcion 5: Insertar un dato en el final de la Lista.");
           printf ("\n Opcion 6: Insertar un numero aleatorio de Items por el final.");
           printf ("\n Opcion 7: Imprimir lista.");
           printf ("\n Opcion 8: Salir");
           printf ("\n\n Elige una opcion: ");
           scanf ("%d", &opcion);
           switch (opcion){
           case 1: //Crear la lista.
                if (!Creada){
                      VaciaLD (&Primero);
                      printf ("\n La lista se ha creado con exito.");
                      Creada = 1;
                }
                else{
                      printf ("\n No se puede crear la lista porque ya esta creada.");
                }
                getchar();
                getchar();
           break;
           case 2: //Comprobar si la lista está vacía.
                if (Creada){ //Si está creada entra.
                     if (EsVaciaLD (Primero)){
                           printf ("\n La lista esta vacia.");      
                     }
                     else{
                           printf ("\n La lista contiene elementos.");
                     }
                }
                else{
                     printf("\n La lista aun no se ha creado.");
                }
                getchar();
                getchar();
           break;
           case 3: //Insertar "dato" al principio de la lista.
                if (Creada){ //Si está creada entra.
                      printf ("\n Introduzca el elemento a insertar: ");
                      scanf ("%d", &dato);
                      InsertaPrincipioLD (&Primero, dato);
                      printf ("\n Elemento %d introducido con exito.", dato);
                }
                else{ 
                      printf("\n No se pueden insertar elementos ya que la lista no se ha creado.");
                }
                getchar();
                getchar();
           break;           
           case 4: //Insertar un número aleatorio de items con valor aleatorio.
                if (Creada){ //Si está creada entra.
                      GeneraPorElPrincipioLD (&Primero);
                      printf ("\n Elementos introducidos con exito.");
                }
                else{ 
                      printf("\n No se pueden insertar elementos ya que la lista no se ha creado.");
                }
                getchar();
                getchar();
           break;                
           case 5: //Insertar un elemento por el final.
                if (Creada){ //Si está creada entra.
                      Nodo *ant;
                      CalcularAnt (Primero, &ant);
                      printf ("\n Introduzca el elemento a insertar: ");
                      scanf ("%d", &dato);
                      InsertaListaDespuesLD (&Primero, &ant, dato);
                      printf ("\n Elemento %d introducido con exito.", dato);
                }
                else{ 
                      printf("\n No se pueden insertar elementos ya que la lista no se ha creado.");
                }
                getchar();
                getchar();           
           break;                
           case 6: //Insertar un número aleatorio de Items por el final.
                if (Creada){ //Si está creada entra.
                      GeneraPorElFinalLD (&Primero);
                      printf ("\n Elementos introducidos con exito.");
                }
                else{ 
                      printf("\n No se pueden insertar elementos ya que la lista no se ha creado.");
                }
                getchar();
                getchar();               
           break;                
           case 7: //Imprimir Lista
                if (Creada){ //Si está creada entra.
                      if (EsVaciaLD (Primero)){ 
                           printf("\n La lista esta vacia.");
                      }
                      else{
                           EscribeLista (Primero);
                      }
                }
                else{ 
                      printf("\n No se pueden imprimir los elementos ya que la lista no se ha creado.");
                }
                getchar();
                getchar();
           break;                           
           case 8: //Salir del programa.
           break;                
           default: //Cualquiera otra opción.
                printf ("\n Opcion invalida, vuelve a intentarlo.\n");
                getchar();
                getchar();
           break;                  
           }        
     }
}

//FUNCIONES, ESTO ES LO QUE PIDE EL EJERCICIO.
//Función que crea la lista.
void VaciaLD (Nodo **Primero){
     *Primero = NULL;   
}

//Función que comprueba si está vacía.
int EsVaciaLD (Nodo *Primero){
    if (Primero == NULL){
         return (true);
    }
    else{
         return (false);
    }  
}

//Función que inserta "dato" al principio de la lista.
void InsertaPrincipioLD (Nodo **Primero, Item dato){
     Nodo *Nuevo;
     Nuevo = (Nodo *)malloc(sizeof(Nodo));
     (*Nuevo).ant = NULL;
     (*Nuevo).sig = NULL;
     (*Nuevo).el = dato;
     if (EsVaciaLD(*Primero)){
          *Primero = Nuevo;
     }
     else{
          (*Nuevo).sig = *Primero;
          (**Primero).ant = Nuevo;
          *Primero = Nuevo;
     }   
}

//Función que introduce un número aleatorio de items con valores aleatorio al principio de la lista.
void GeneraPorElPrincipioLD (Nodo **Primero){
     int numeros, i;
     Item dato;
     numeros = rand () % 100;
     
     for (i=0;i<numeros;i++){
         dato = rand () % 100;
         InsertaPrincipioLD (&(*Primero), dato);  
     }         
}

//Función que inserta "dato" al final de la lista.
void InsertaListaDespuesLD (Nodo **Primero, Nodo **ant, Item d){
     //Se supone que "ant" llega y apunta al último nodo. 
     Nodo *Nuevo;
     Nuevo = (Nodo *)malloc(sizeof(Nodo));
     (*Nuevo).ant = NULL;
     (*Nuevo).sig = NULL;
     (*Nuevo).el = d;
     if (EsVaciaLD(*Primero)){
          *Primero = Nuevo;
          *ant = Nuevo;
     }
     else{
          (*Nuevo).ant = *ant;
          (**ant).sig = Nuevo;
          *ant = Nuevo;
     }   
}

//Función que inserta un número aletario de valores al final de la lista.
void GeneraPorElFinalLD (Nodo **Primero){
     //No nos dan "ant" por tanto llamamos a la función CalcularAnt. 
     Nodo *ant;
     CalcularAnt (*Primero, &ant);
     int numeros, i;
     Item dato;
     
     numeros = rand () % 100;
     
     for (i=0;i<numeros;i++){
         dato = rand () % 100;
         InsertaListaDespuesLD (&(*Primero), &ant, dato);  
     }        
}

//Calcula "ant" que apunta al último. Para ello recorre la lista desde el principio hasta llegar al último.
void CalcularAnt (Nodo *Primero, Nodo **ant){
     *ant = Primero;
     if (!EsVaciaLD(Primero)){
             while ((**ant).sig != NULL){
                   *ant = (**ant).sig;
             } 
     }  
}

//Imprimir la lista.
void EscribeLista (Nodo *Primero){
     printf ("\n");
     while (Primero != NULL){
           printf (" [%d]", (*Primero).el);
           Primero = (*Primero).sig;
     }   
}
