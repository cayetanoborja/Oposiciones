/***********************************************************************************/
/******************************* EJERCICIO TAD COLA C ******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//DEFINIMOS LAS ESTRUCTURAS.
typedef int tDato;

typedef struct nodo{
	tDato elemento;
	struct nodo *siguiente, *anterior;
}tCelda;

typedef struct{
	tCelda *primero, *ultimo;
}tCola;

typedef tCola *TipoCola;

//DECLARAMOS LAS FUNCIONES.
void crearCola (TipoCola *Cola);
int estaCreada (TipoCola Cola);
int esVacia (TipoCola Cola);
void InsertarElemento (TipoCola *Cola, tDato elemento);
int recorridoCola (TipoCola Cola);
void eliminarElemento (TipoCola Cola);

//EJECUTAMOS EL PROGRAMA.
int main(){

int opcion;
TipoCola Cola;
Cola = NULL;
void InsertarElemento (TipoCola *Cola, tDato elemento);
	while (opcion !=8){
		system ("cls");
		printf ("Opcion 1: Crear Cola");
		printf ("\nOpcion 2: Comprobar si esta vacia");
		printf ("\nOpcion 3: Insertar elemento");
		printf ("\nOpcion 4: Eliminar un elemento");
		printf ("\nOpcion 5: Comprobar el primer elemento");
		printf ("\nOpcion 6: Comprobar el ultimo elemento");
		printf ("\nOpcion 7: Recorrer Cola");
		printf ("\nOpcion 8: Salir");
		printf ("\n\nEscoge una opcion: ");
		scanf ("%d", &opcion);
		
		switch (opcion){
			case 1: //Creamos la cola
				crearCola (&Cola);
				printf("\nLa cola se ha creado.");
			break;
			case 2: //Comprobamos si la cola está vacía.
				if (estaCreada (Cola)) {//Primero comprobamos si se ha creado.	
					if (esVacia(Cola))
						printf("\nLa cola esta vacia");
					else
						printf("\nLa cola contiene elementos");
				}
				else
					printf("\nPara comprobar si la cola esta vacia debes creala primero");
			break;
			case 3: //Insertamos un elemento en la cola.
				if (estaCreada (Cola)) {//Primero comprobamos si se ha creado.	
					tDato elemento;
					printf ("\nIntroduce el elemento: ");
					scanf ("%d",&elemento);
					InsertarElemento (&Cola, elemento);
					printf("\nEl elemento %d ha sido insertado.\n", elemento);
				}
				else
					printf("\nPara insertar un elemento, primero tienes que crear la cola");
			break;
			case 4: //Eliminar un elemento.
				if (estaCreada (Cola)) { //Primero comprobamos si se ha creado.	
					if (esVacia(Cola))
						printf("\nNo se pueden eliminar elementos porque la cola esta vacia.");
					else
						eliminarElemento (Cola);
				}
				else
					printf("\nNo se pueden eliminar elementos porque la cola no esta creada");
			break;
			case 5: //Mostrar el primer elemento.
				if (estaCreada (Cola)) {//Primero comprobamos si se ha creado.	
					if (esVacia(Cola))
						printf("\nLa cola esta vacia");
					else
						printf("\nNo implementado");
				}
				else
					printf("\nPara comprobar si la cola esta vacia debes creala primero");
			break;
			case 6: //Mostrar el ultimo elemento.
				if (estaCreada (Cola)) {//Primero comprobamos si se ha creado.	
					if (esVacia(Cola))
						printf("\nLa cola esta vacia");
					else
						printf("\nNo implementado");
				}
				else
					printf("\nPara comprobar si la cola esta vacia debes creala primero");
			break;
			case 7: //Recorre la cola.
				if (estaCreada (Cola)) {//Primero comprobamos si se ha creado.	
					if (esVacia(Cola))
						printf("\nLa cola esta vacia.");
					else{
						printf("\nLa cola tiene los siguientes elementos: ");
						recorridoCola (Cola);
					}
				}
				else
					printf("\nPara recorrer la cola debes creala primero");
			break;
			case 8: //Sale del programa.
				printf("\nAdios");
			break;
			default: //Cualquier otra opción.
				printf ("\nOpcion incorrecta. Intentalo de nuevo");
			break;
		}
		getchar();getchar();
	}
}

//CREAMOS LAS FUNCIONES.
//Función crear cola.
void crearCola (TipoCola *Cola){
	*Cola = (TipoCola)malloc(sizeof(tCola));
	(**Cola).primero = NULL;
	(**Cola).ultimo = NULL;
}

//Función que comprueba si la cola se ha creado o no.
int estaCreada (TipoCola Cola){
	if (Cola == NULL)
		return 0;
	else
		return 1;
}

//Función comprobar si está vacía.
int esVacia (TipoCola Cola){
	if ((Cola == NULL) || ((*Cola).primero == NULL))
		return 1;
	else
		return 0;
}

//Función que inserta un elemento en la cola.
void InsertarElemento (TipoCola *Cola, tDato elemento){

	tCelda *Nodo;
	Nodo = (tCelda*)malloc(sizeof(tCelda));
	
	(*Nodo).elemento = elemento;
	(*Nodo).siguiente = NULL;
	(*Nodo).anterior = NULL;
	
		if (esVacia(*Cola)){
			(**Cola).primero = Nodo;
			(**Cola).ultimo = Nodo;		
		}
		else
		{
			(*Nodo).siguiente = (**Cola).primero;
			(*Nodo).anterior = NULL;
			(*((**Cola).primero)).anterior = Nodo;
			(**Cola).primero = Nodo;
		}
}


//Función que elimina un elemento de la cola.
void eliminarElemento (TipoCola Cola){

	if ((*Cola).ultimo == (*Cola).primero) { //Solo existe un elemento.
		printf ("\nSe ha eliminado el elemento %d ", (*(*Cola).ultimo).elemento);
		free ((*Cola).ultimo);
		(*Cola).primero = NULL;
		(*Cola).ultimo = NULL;
	}
	else {//Existen más de uno.
		printf ("\nSe ha eliminado el elemento %d ", (*(*Cola).ultimo).elemento);
		(*Cola).ultimo = (*(*Cola).ultimo).anterior;
		free ((*(*Cola).ultimo).siguiente);
		(*(*Cola).ultimo).siguiente = NULL;
	}
}

//Función que recorre la cola.
int recorridoCola (TipoCola Cola){

	tCelda *Ptr;
		if (esVacia(Cola))
			printf ("\nLa cola esta vacia");	
		else {
			Ptr = (*Cola).primero;
			while (Ptr != NULL) {//Mientras la cola no llegue al final repite.
				printf ("[%d] ", (*Ptr).elemento);
				Ptr = (*Ptr).siguiente;
			}	
		}
}

