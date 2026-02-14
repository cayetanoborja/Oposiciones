/*  PILAS CON LISTAS DOBLES.
Funciones: poner, quitar y listar,.
Crear un programa en C, tenga un menu de gestion de colas
con listas dobles.
con las siguientes opciones: 0 salir, 1 poner ,2 quitar, 3 listar,
Cada una de estar opciones llama a una funcion que lo realiza.
La lista sera de enteros. Quitar debe liberar memoria.
*/

#include <stdio.h> // printf, scanf, getchar
#include <stdlib.h> // malloc()

typedef struct nodo{
 int x;
 struct nodo *sig;
 struct nodo *ant;
}nodo;

// ***************** Listado de la lista
void listar (nodo *primero) {

//printf("\n*** Listado ***\n");

if (primero!=NULL)
   {
 	printf("%d ",primero->x);
	listar(primero ->sig);
   }
}

// ***************** Ponemon un nodo
en la cabeza
void poner (nodo **cabeza, nodo *nuevo) {

if (*cabeza == NULL){
	*cabeza = nuevo;
   (*cabeza)->sig = NULL;
   (*cabeza)->ant = NULL;
   }
   else
   {
   nuevo->sig = *cabeza;
   nuevo->ant = NULL;
   *cabeza = nuevo;
   }
}
// **************************************
void ponernodo(nodo **cabeza)
{
int i;
nodo *nuevo;

printf("\n*** Insercion ***");
printf("\nValor: "); scanf("%d",&i);
while (i!=0)
{
nuevo = (nodo *) malloc( sizeof(nodo) );
nuevo->x= i;
poner(cabeza,nuevo);
// Si esta en la lista se libera memoria

printf("Valor: "); scanf("%d",&i);
}
listar(*cabeza);
}

// ************** Quitar
// Quitamo nodo de la cola.
nodo *quitar(nodo **cabeza)
{
nodo *nuevo;

nuevo=*cabeza;

if (*cabeza==NULL)
	return *cabeza;
else
	{
   *cabeza= (*cabeza)->sig;
	if ( cabeza!=NULL) (*cabeza)->ant = NULL;
	return nuevo;
	}
}
// ************* Quitar Nodos enteros
void quitarnodo(nodo **cabeza)
{
nodo *borrar;
printf("\n*** Quitar nodo pila***\n");
borrar = quitar(cabeza);
if (borrar ==0)
  printf("No se puede borrar\n");
else
  free(borrar);
listar(*cabeza);
}

// ******************** main
int main() {
int op;
nodo *cabeza=NULL;

do {
printf("\n*** PILAS CON LISTAS DOBLEMENTE ENLAZADAS***");
printf("\n0. Salir");
printf("\n1. Poner");
printf("\n2. Quitar");
printf("\n3. Listar todo");
printf("\nOpcion: ");scanf("%d",&op);
switch (op) {
case 1: ponernodo(&cabeza); break;
case 2: quitarnodo(&cabeza); break;
case 3: listar(cabeza); break;
}
} while (op !=0);

printf("\nFin"); 
return 0;
}
