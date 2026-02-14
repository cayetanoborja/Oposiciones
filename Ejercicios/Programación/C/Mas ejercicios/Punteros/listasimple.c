// listasimple.c
#include <stdio.h>
#include <stdlib.h>
#include "listasimple.h"

TipoLista lista_vacia (void)
{
	return NULL;
}

int es_lista_vacia (TipoLista lista)
{
	return lista == NULL;
}

TipoLista inserta_por_cabeza (TipoLista lista, int valor)
{
	struct Nodo *nuevo = malloc (sizeof (struct Nodo));

	nuevo->info = valor;
	nuevo->sig = lista;
	lista = nuevo;
	return lista;
}

TipoLista inserta_por_cola (TipoLista lista, int valor)
{
	struct Nodo *aux, *nuevo;

	nuevo = malloc (sizeof (struct Nodo));
	nuevo->info = valor;
	nuevo->sig = NULL;
	if (lista == NULL)
		lista = nuevo;
	else {
		for (aux = lista; aux->sig != NULL; aux = aux->sig);
		aux->sig = nuevo;
	}
	return lista;
}

TipoLista borra_cabeza (TipoLista lista)
{
	struct Nodo *aux;

	if (lista != NULL) {
		aux = lista->sig;
		free (lista);
		lista = aux;
	}
	return lista;
}

TipoLista borra_cola (TipoLista lista)
{
	struct Nodo *aux, *atras;

	if (lista != NULL) {
		for (atras = NULL, aux = lista; aux->sig != NULL;
			 atras = aux, aux = aux->sig);
		free (aux);
		if (atras == NULL)
			lista = NULL;
		else
			atras->sig = NULL;
	}
	return lista;
}

int longitud_lista (TipoLista lista)
{
	struct Nodo *aux;
	int contador = 0;

	for (aux = lista; aux != NULL; aux = aux->sig)
		contador++;
	return contador;
}

void muestra_lista (TipoLista lista)
{								// Como la solución al ejercicio muestralista, no como lo vimos en el texto.
	struct Nodo *aux;

	printf ("->");
	for (aux = lista; aux != NULL; aux = aux->sig)
		printf ("[%d]->", aux->info);
	printf ("|\n");
}

int pertenece (TipoLista lista, int valor)
{
	struct Nodo *aux;

	for (aux = lista; aux != NULL; aux = aux->sig)
		if (aux->info == valor)
			return 1;
	return 0;
}

TipoLista borra_primera_ocurrencia (TipoLista lista, int valor)
{
	struct Nodo *aux, *atras;

	for (atras = NULL, aux = lista; aux != NULL; atras = aux, aux = aux->sig)
		if (aux->info == valor) {
			if (atras == NULL)
				lista = aux->sig;
			else
				atras->sig = aux->sig;
			free (aux);
			return lista;
		}
	return lista;
}

TipoLista borra_valor (TipoLista lista, int valor)
{
	struct Nodo *aux, *atras;

	atras = NULL;
	aux = lista;
	while (aux != NULL) {
		if (aux->info == valor) {
			if (atras == NULL)
				lista = aux->sig;
			else
				atras->sig = aux->sig;
			free (aux);
			if (atras == NULL)
				aux = lista;
			else
				aux = atras->sig;
		} else {
			atras = aux;
			aux = aux->sig;
		}
	}
	return lista;
}

TipoLista inserta_en_posicion (TipoLista lista, int pos, int valor)
{
	struct Nodo *aux, *atras, *nuevo;
	int i;

	nuevo = malloc (sizeof (struct Nodo));
	nuevo->info = valor;

	for (i = 0, atras = NULL, aux = lista; i < pos && aux != NULL;
		 i++, atras = aux, aux = aux->sig);
	nuevo->sig = aux;
	if (atras == NULL)
		lista = nuevo;
	else
		atras->sig = nuevo;
	return lista;
}

TipoLista inserta_en_orden (TipoLista lista, int valor)
{
	struct Nodo *aux, *atras, *nuevo;

	nuevo = malloc (sizeof (struct Nodo));
	nuevo->info = valor;

	for (atras = NULL, aux = lista; aux != NULL; atras = aux, aux = aux->sig)
		if (valor <= aux->info) {
			/* Aquí insertamos el nodo entre \emph{atras} y \emph{aux}. */
			nuevo->sig = aux;
			if (atras == NULL)
				lista = nuevo;
			else
				atras->sig = nuevo;
			/* Y como ya está insertado, acabamos. */
			return lista;
		}
	/* Si llegamos aquí, es que \emph{nuevo} va al final de la lista. */
	nuevo->sig = NULL;
	if (atras == NULL)
		lista = nuevo;
	else
		atras->sig = nuevo;
	return lista;
}

TipoLista concatena_listas (TipoLista a, TipoLista b)
{
	TipoLista c = NULL;
	struct Nodo *aux, *nuevo, *anterior = NULL;

	for (aux = a; aux != NULL; aux = aux->sig) {
		nuevo = malloc (sizeof (struct Nodo));
		nuevo->info = aux->info;
		if (anterior != NULL)
			anterior->sig = nuevo;
		else
			c = nuevo;
		anterior = nuevo;
	}
	for (aux = b; aux != NULL; aux = aux->sig) {
		nuevo = malloc (sizeof (struct Nodo));
		nuevo->info = aux->info;
		if (anterior != NULL)
			anterior->sig = nuevo;
		else
			c = nuevo;
		anterior = nuevo;
	}
	if (anterior != NULL)
		anterior->sig = NULL;
	return c;
}

void libera_lista (TipoLista * lista)
{
	struct Nodo *aux, *otroaux;

	aux = *lista;
	while (aux != NULL) {
		otroaux = aux->sig;
		free (aux);
		aux = otroaux;
	}

}
