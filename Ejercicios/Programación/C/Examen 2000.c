/***********************************************************************************/
/*******************APARTADO EJERCICIO EXÁMEN 2000: SUPUESTO 1**********************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*
Diremos que un árbol n-ario está ordenado si para cualquier nodo n, el número de nodos de los
subárboles que cuelgan de n aumenta de izquierda a derecha, esto es, si del nodo n cuelgan los
subárboles T1, T2, ... , Tk, el número de nodos de Ti es menor o igual que el de Ti+1 (1 <= i< k).

Dada la siguiente definición de una estructura en C:
     typedef struct DefTNodo{
             struct DefTNodo *pHijos; // puntero a un array de punteros a los subárboles hijos
             int nhijos;              // número ode hijos que tiene el árbol
             int elem;                // elemento que almacena el árbol.
     }TNodo;
     
Crear una función que retorne si un árbol n-ario es ordenado. La función tendrá el siguiente prototipo:
      int estaOrdenado (TNodo *pRaiz); //Retornará 0 si no está ordenado, otro valor si está ordenado

Nota: Explicar claramente con comentarios el algoritmo y utilizar el lenguaje C.

Ejemplo: Si un árbol tiene 3 hijos, el número de hijos del primer subárbol ha de ser
menor o igual que del segundo y el número de hijos del segundo subárbol ha de ser
menor o igual que del tercer subárbol. Así con todos los subárboles*/


/***********************************************************************************/
/*************************DECLARAMOS LAS ESTRUCTURAS********************************/
/***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct DefTNodo {
	struct DefTNodo *pHijos;
	int nhijos;
	int elem;
}TNodo;

int estaOrdenado(TNodo *pRaiz);

int main(){}

int estaOrdenado(TNodo *pRaiz){
	int i;
	int n = (*pRaiz).nhijos;
	if (n != 0){  //Si tiene hijos.
		for (i=0;i<n;i++){
			if (i == (n-1))
				estaOrdenado (&(*pRaiz).pHijos[i]);
			else{
				if ((*&(*pRaiz).pHijos[i]).nhijos > (*&(*pRaiz).pHijos[i+1]).nhijos)
					return 0;
				else
					estaOrdenado (&(*pRaiz).pHijos[i]);
			}              
		}
	}
	return 1;
}



