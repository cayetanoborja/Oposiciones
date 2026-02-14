/* LISTAS DOBLEMENTE ENLAZADAS ORDENADAS.

Crear un programa en C, tenga un menu de gestion de listas dobles ordenadas
con las siguientes opciones: 0 salir, 1 insertar ,2 listar, 3 borrar todo,
4 borrar uno.
Cada una de estar opciones llama a una funcion que lo realiza.
La lista sera de enteros. */

#include <stdio.h> // printf, scanf, getchar
#include <stdlib.h> // malloc()

typedef struct nodo{
 int x;
 struct nodo *sig;
 struct nodo *ant;
}nodo;


// ***************** Listado de la lista doble
void listar (nodo *primero) {
nodo *nuevo;
printf("\n*** Listado ***\n");
nuevo= primero;
while (nuevo!=NULL) {
 	printf("%d ",nuevo->x);
	nuevo =  nuevo->sig; }
}

/* ************ Buscar nodo a Borrar
Deuelve el puntero del nodo cuyo valor esta
en buscado.
*/
nodo  *buscarnodoaborrar(nodo *primero, nodo *buscado)
{
nodo *aux;

aux= primero;
while (aux != NULL)
{
if (buscado->x == aux->x) // encontrado
   return aux;
else if (buscado->x < aux->x) // No esta
   return NULL;
aux = aux->sig;
}
return NULL;
}

// ************* Borrar de Nodos
int borrarnodo(nodo **principio, nodo *borrar )
{
nodo  *aborrar;

if (*principio==NULL)
  return 0;
else
   {
   aborrar = buscarnodoaborrar(*principio,borrar);
   if (aborrar == NULL)
       return 0;
   else if (aborrar == *principio)
         {
         *principio = aborrar->sig;
//         (*principio)->ant = NULL; //Solo circulares. Correguido.
         free(aborrar);
     		}
        else
        {
        aborrar->ant->sig = aborrar->sig;
        if (aborrar->sig !=NULL) //correguido
          aborrar->sig->ant = aborrar->ant;
        free(aborrar);
        }
   }
return 1;
}

/* ************ Borrar de Nodos enteros
Borra los nodos indicados hasta
introducir un 0.
*/

void borraruno(nodo **primero)
{
int i;
nodo *borrar;

printf("\n*** Borrado de un nodo ***");
printf("\nValor a borrar: "); scanf("%d",&i);

while (i!=0)
{
borrar = (nodo *) malloc( sizeof(nodo) );
borrar->x= i;
if (borrarnodo(primero, borrar) ==0)
  printf("No encontrado");
free(borrar);
listar(*primero);
printf("\nValor a Borrar: "); scanf("%d",&i);
}
}

// ***************** Borrar
void borrartodo (nodo **primero) {
nodo *aux;
printf("\n*** Borrado de todo ***\n");
aux= *primero;
while (*primero != NULL) {
   *primero = aux->sig;   printf("\nBorrado %d ",aux->x);
   free(aux); 	aux = *primero; }
}


/* ***************** Buscar nodo
Devuelve: el nodo anterior al que debe inserta o null si esta repetido.
repetido vale 0 si esta repetido, y 1 sino no lo esta
*/
nodo  *buscarnodo(nodo *principio, nodo *nuevo, int *repetido){
nodo *aux;
aux= principio;
if  (aux->x == nuevo->x) // son iguales
{  *repetido = 1;   return NULL; }
else if (aux->x < nuevo->x && aux->sig == NULL )
{  *repetido = 0;   return aux;  }
else if (aux->x > nuevo->x)
{  *repetido = 0; return NULL; }

// Mientras sea mayor pasamos al siguiente.
while (aux->sig != NULL) {
  if  (aux->sig->x == nuevo->x) // son iguales
  {  *repetido = 1;   return NULL; }
  else if (aux->sig->x > nuevo->x)
       {  *repetido = 0; return aux; }
  aux = aux-> sig;
}

return aux;
}

/* **************** Insercion en orden
Inserta el nodo nuevo en la lista apuntada por principio.
No inserta duplicados.
*/
int insertarorden(nodo **principio, nodo *nuevo)
{
nodo *anterior;
int esta=0;

if (*principio==NULL) // Insertar al principio
{
 *principio = nuevo;
 nuevo->sig = NULL;
 nuevo->ant = NULL;
}
else
{
anterior = buscarnodo(*principio, nuevo, &esta);
if (esta) // Esta en la lista
{
   printf("El elemento existe en la lista\n");
   return 0;
}
else

    if (anterior == NULL)
    {
    nuevo->sig = *principio;
    (*principio)->ant = nuevo;
    *principio = nuevo;
    nuevo->ant = NULL;
    }
    else
    {
    nuevo-> sig = anterior->sig;
    anterior-> sig = nuevo;
    anterior->sig->ant = nuevo;
    nuevo->ant = anterior;
    }
}
return 1;
}

/****** Insercion ordenada de enteros.
Va pidiendo numeros enteros hasta que
se introduce un 0. Los inserta en la
lista de forma ordenada.
*/
void insertar(nodo **primero)
{
int i;
nodo *nuevo;

printf("\n*** Insercion ***");
printf("\nValor: "); scanf("%d",&i);
while (i!=0)
{
nuevo = (nodo *) malloc( sizeof(nodo) );
nuevo->x= i;

// Si esta en la lista se libera memoria
if ( insertarorden(primero,nuevo)== 0)
free(nuevo);

printf("Valor: "); scanf("%d",&i);
}
listar(*primero);
}

// ******************** main
int main() {
int op;
nodo *primero;
primero = NULL;
do {
printf("\n*** MENU LISTAS DOBLEMENTE ENLAZADAS ORDENADAS ***");
printf("\n0. Salir");
printf("\n1. Insertar");
printf("\n2. Listar todo");
printf("\n3. Borrar todo");
printf("\n4. Borrar un nodo");
printf("\nOpcion: ");scanf("%d",&op);
switch (op) {
case 1: insertar(&primero); break;
case 2: listar(primero); break;
case 3: borrartodo(&primero); break;
case 4: borraruno(&primero); break;
}
} while (op !=0);

printf("Fin\n");
return 0;
}
