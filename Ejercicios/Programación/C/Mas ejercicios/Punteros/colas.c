/* COLAS.C.
funciones: poner, quitar y listar,.
Crear un programa en C, tenga un menu de gestion de colas
con las siguientes opciones: 0 salir, 1 poner ,2 quitar, 3 listar,
Cada una de estar opciones llama a una funcion que lo realiza.
La lista sera de enteros. Quitar debe liberar memoria.
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc()

typedef struct nodo{
 int x;
 struct nodo *sig;
 struct nodo *ant;
}nodo;

// ***************** Listado de la lista
// Recorremos la cola desde la cabeza la final
void listar (nodo *cabeza) {
nodo *aux;

//printf("\n*** Listado ***\n");
if (cabeza!=NULL)
	for (aux=cabeza;aux!=NULL;aux=aux->sig)
	printf("%d\n",aux->x);
}

// Pone el nodo nuevo al final de la cola.
void poner (nodo **cabeza, nodo *nuevo) {
nodo *aux;
	
if (*cabeza == NULL){
   *cabeza = nuevo;
   (*cabeza)->sig = NULL;
   (*cabeza)->ant = NULL;
   }
   else
   {
	for (aux=*cabeza;aux->sig!=NULL;aux=aux->sig);
	 aux->sig = nuevo;
     nuevo->ant=aux;
   }
}

// **************************************
// Se pone nodo al final de la cabeza
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
nuevo->sig= NULL;
poner(cabeza,nuevo);
printf("Valor: "); scanf("%d",&i);
}
listar(*cabeza);
}

// ************** Quitar
// Quitamos el nodo de la cabeza

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
// Quita nodo de la cabeza.

void quitarnodo(nodo **cabeza)
{
nodo *borrar;
printf("\n*** Quitar nodo pila***\n");
borrar = quitar(cabeza);
if (borrar ==0)
  printf("\n Vacia");
else
  free(borrar);
  listar(*cabeza);
}

// ******************** main
int main() {
int op;
nodo *cabeza=NULL;

do {
printf("\n*** COLAS CON LISTAS DOBLEMENTE ENLAZADAS***");
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
