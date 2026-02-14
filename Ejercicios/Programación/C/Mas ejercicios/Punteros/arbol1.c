/* arbol.c Arbol Binario de Busqueda.
Por Paco Aldarias
*/

/* Ficheros a incluir: */

#include <stdio.h>  /* printf (), scanf (), puts () */
// #include <conio.h>  /* windows getchar () */
#include <stdlib.h> /* exit (), malloc, free */
// #include <alloc.h>  /* windows malloc (), free () */
#include <string.h> /* strchr () */

/* Estructuras y tipos globales: */

typedef struct nodo
  {
    int info;
    struct nodo *pizq, *pder;
  } nodo;

/********************
Otra forma de definir el arbol seria

struct nodo
{
   int info;
   struct nodo *pizq, *pder;
};
typedef struct nodo *arbol;

*********************** */


/* Prototipos de las funciones: */

void empezar_arbol (nodo **parb);
void terminar_arbol (nodo **parb);
void crear_nodo_arbol (nodo **pa);
void liberar_nodo_arbol (nodo **pa);
void aniadir_a_arbol (nodo **parb, int info);
int quitar_de_arbol (nodo **parb, int info);
void suprimir_nodo_de_arbol (nodo **p);
nodo *buscar_en_arbol (nodo *parb, int info);
void imprimir_arbol_en_preorden (nodo *parb);
void imprimir_arbol_en_postorden (nodo *parb);
void imprimir_arbol_en_inorden (nodo *parb);

/* Definicion de funciones: */

/*
  funcion principal.
*/

int main (void)
{
  int salir = 0;
  char ch;
  nodo *parbol;
  int num;

  puts ("\nPROGRAMA PARA PROBAR OPERACIONES CON UN ARBOL.");
  empezar_arbol (&parbol);
  do
    {
     printf ("\nOperacion a realizar([A]nadir, [Q]uitar,\
		[B]uscar,[P]reorden,Pos[T]orden,[I]norden ,[S]alir): ");
     do
        {
          ch = getchar ();
        } while (strchr ("aAqQbBsSpPTtiI", ch) == NULL);

      switch (putchar (ch))
        {
          case 'a':  case 'A':
            printf ("\n\nIntroduce numero a anadir: ");
            scanf ("%d", &num);
            aniadir_a_arbol (&parbol, num);
            break;
          case 'q':   case 'Q':
            printf ("\n\nIntroduce numero a quitar: ");
            scanf ("%d", &num);
            if (quitar_de_arbol (&parbol, num))
              printf ("\nNumero %d quitado del arbol.\n", num);
            else
              printf ("\nEl numero %d no se encuentra en el arbol.\n", num);
            break;
          case 'b':  case 'B':
            printf ("\n\nIntroduce numero a buscar: ");
            scanf ("%d", &num);
            printf ("\nNumero %d %s encontrado.\n", num,
                    buscar_en_arbol (parbol, num) != NULL ? " " : " no ");
            break;
          case 'p':  case 'P':
             	printf ("\n\nElementos en  arbol en Preorden: ");
             	if (parbol == NULL) printf ("(ninguno)");
             	else imprimir_arbol_en_preorden (parbol);
		break;
          case 't': case 'T':
		printf ("\n\nElementos en  arbol en postorden: ");
                if (parbol == NULL) printf ("(ninguno)");
                else imprimir_arbol_en_postorden (parbol);
		break;
          case 'i': case 'I':
		printf ("\n\nElementos en  arbol en Inorden: ");
                if (parbol == NULL) printf ("(ninguno)");
                else imprimir_arbol_en_inorden (parbol);
                break;
          case 's':
          case 'S':
            salir = 1;
        }
    } while (! salir);
  terminar_arbol (&parbol);
return 0;
}

/*
  La primera operacicion que hay que hacer siempre con un arbol es inicializarlo,
  esto consiste en asignar NULL al puntero que apunta a la cabeza del arbol.
*/

void empezar_arbol (nodo **parb)
{
  *parb = NULL;
}

/*
  Antes de acabar el programa es conveniente liberar la memoria asignada
  din micamente. Para ello, lo unico que se hace es recorrer todo el
  arbol liberando cada nodo con free().
*/

void terminar_arbol (nodo **parb)
{
  if (*parb != NULL)
    {
      terminar_arbol ( &(*parb)->pizq );
      terminar_arbol ( &(*parb)->pder );
      liberar_nodo_arbol (parb);
    }
}

/*
  Asigna memoria para un nodo del arbol.
  Si no hay suficiente memoria, el programa presenta un mensaje de error
  y termina.
*/

void crear_nodo_arbol (nodo **pa)
{
  if ((*pa = (nodo *) malloc (sizeof (nodo))) == NULL)
    {
      printf ("\nERROR: Memoria insuficiente.");
      exit (1);
    }
}

/*
  Libera memoria asignada con malloc, de este modo esta memoria puede
  ser reutilizada.
*/

void liberar_nodo_arbol (nodo **pa)
{
  free (*pa);
}

/*
  Para ver como se inserta en lo arboles, veamos como se insertaran
  los siguientes numeros en un arbol donde informacicn es un numero
  entero:

    3 10 2 -1 0 3 8 20

  Paso 0:
              parbol
                |
                v
               NULL
  Paso 1:
              parbol
                |
                v
                3
  Paso 2:
              parbol
                |
                v
                3
                 \
                  10
  Paso 3:
              parbol
                |
                v
                3
               / \
              2   10
  Paso 4:
              parbol
                |
                v
                3
               / \
              2   10
             /
           -1
  Paso 5:
              parbol
                |
                v
                3
               / \
              2   10
             /
           -1
             \
              0
  Paso 6:
              parbol
                |
                v
                3
               / \
              2   10
             /   /
           -1   3
             \
              0
  Paso 7:
              parbol
                |
                v
                3
               / \
              2   10
             /   /
           -1   3
             \   \
              0   8
  Paso 8:
              parbol
                |
                v
                3
               / \
              2   10
             /   /  \
           -1   3    20
             \   \
              0   8

*/

void aniadir_a_arbol (nodo **parb, int info)
{
  nodo *p, *pant; /* punteros utilizados para la busqueda */
  nodo *pa; /* puntero que apunta a nuevo nodo creado y que hay que insertar */

  crear_nodo_arbol (&pa);
  pa->info = info;
  pa->pizq = NULL;
  pa->pder = NULL;

  p = *parb;
  pant = NULL;
  while (p != NULL) /* busca lugar de insercion */
    {
      pant = p;
      if (p->info > info)
        p = p->pizq;
      else
        p = p->pder;
    }

  if (pant == NULL) /* inserta en lugar correspondiente */
    *parb = pa;
  else if ( pant->info > info)
    pant->pizq = pa;
  else
    pant->pder = pa;
}

/*
  Quita el primer nodo encontrado que contenga el valor info en el
  campo informacicn del nodo.
  Devuelve TRUE si se borra el elemento o FALSE en caso contrario.
*/

int quitar_de_arbol (nodo **parb, int info)
{
 nodo *p = *parb, *pant = NULL;
 int encontrado = 0;

  while (p != NULL && ! encontrado) /* busca nodo a borrar */
    if ( p->info == info)
      encontrado = 1;
    else
      {
        pant = p;
        if ( p->info > info)
          p = p->pizq;
        else
          p = p->pder;
      }

  if (encontrado) 
 /* llama a la funcion suprimir con puntero apuntado a nodo a quitar */
    if (p == *parb)
      suprimir_nodo_de_arbol (parb);
    else if ( pant->pizq == p)
      suprimir_nodo_de_arbol (&pant->pizq);
    else
      suprimir_nodo_de_arbol (&pant->pder);

  return (encontrado);
}

/*
  Suprime nodo de arbol apuntado por p.
  Esta funcion es llamada por la funcion quitar_de_arbol.
  Hay tres situaciones diferentes a la hora de suprimir un nodo, a saber:
  Sea el arbol compuesto de numeros reales:

                                        5
                                      /   \
                                     3     8
                                    / \   / \
                                   2   4 6   9
                                  /     / \
                                 1    5.5  7
                                          /
                                         6.5

  Situacion 1: suprimir nodo sin hijo derecho; por ejemplo, el nodo 7, en
  este caso el puntero p es el puntero derecho del nodo 6; la accion a
  realizar es: p = pizq (p).

  Situacion 2: suprimir nodo sin hijo izquierdo; por ejemplo, el nodo 1, en
  este caso el puntero p es el puntero izquierdo del nodo 2; la accion a
  realizar es: p = pder (p).

  Situacion 3: suprimir nodo intermedio, es decir, nodo con hijos izquierdo
  y derecho; por ejemplo, el nodo 8, en este caso el puntero p es el
  puntero derecho del nodo 5; la accion a realizar es sustituir el contenido
  del nodo a suprimir (nodo 8) por el mayor contenido entre los nodos del
  subarbol izquierdo, que se calcula como el nodo m s a la derecha a partir
  del nodo izquierdo del nodo a suprimir, en este caso el nodo izquierdo es
  6 y recorriendo los punteros a la derecha hasta llegar al final, nos
  paramos en el nodo 7, copiamos el contenido del nodo 7 en el nodo 8 y
  ahora tenemos que suprimir un nodo (el 7 en este caso) que ya pertenece
  a uno de los dos casos anteriores.
*/

void suprimir_nodo_de_arbol (nodo **p)
{
  nodo *ptemp = *p;

  if ( (*p)->pder == NULL) /* situacion 1 */
    *p = (*p)->pizq;
  else if ((*p)->pizq == NULL) /* situacion 2 */
    *p = (*p)->pder;
  else /* situacion 3 */
    {
      nodo *pant = *p;

      ptemp = (*p)->pizq;
      while ((ptemp)->pder != NULL) /* recorremos punteros a derecha a partir ... */
        { /* ... puntero a izquierda del nodo apuntado por el puntero a suprimir */
          pant = ptemp;
          ptemp = ptemp->pder;
        }
      (*p)->info = (ptemp)->info;
      if (pant == *p)
        pant->pizq = ptemp->pizq;
      else
        pant->pder = ptemp->pizq;
    }

  liberar_nodo_arbol (&ptemp);
}

/*
  Devuelve un puntero al nodo del arbol que contiene info. 
  Si ningun nodo del arbol contiene el dato info, devuelve NULL.
*/

nodo *buscar_en_arbol (nodo *parb, int info)
{
  nodo *p = parb;
  int encontrado = 0;

  while (p != NULL && ! encontrado)
    if (p->info == info)
      encontrado = 1;
    else if ( p->info > info)
      p = p->pizq;
    else
      p = p->pder;

  return (p); /* p valdr  NULL si info no se ha encontrado */
}

/*
  Imprime todos los elementos del arbol haciendo un recorrido en preorden.
*/

void imprimir_arbol_en_preorden (nodo *parb)
{
  if (parb != NULL)
    {
      printf ("%d [ ", parb->info);
      imprimir_arbol_en_preorden (parb->pizq); /* imprime subarbol izquierdo */
      imprimir_arbol_en_preorden (parb->pder); /* imprime subarbol derecho */
      printf (" ]");
    }
}

/*
  Imprime todos los elementos del arbol haciendo un recorrido en postorden.
*/

void imprimir_arbol_en_postorden (nodo *parb)
{
  if (parb != NULL)
    {
      imprimir_arbol_en_postorden (parb->pizq); /* imprime subarbol izquierdo */
      imprimir_arbol_en_postorden (parb->pder); /* imprime subarbol derecho */
      printf ("%d ", parb->info);
    }
}

/*
  Imprime todos los elementos del arbol haciendo un recorrido en inorden.
  Si el arbol est  ordenado, este recorrido imprime los elementos ordenados.
*/

void imprimir_arbol_en_inorden (nodo *parb)
{
  if (parb != NULL)
    {
      imprimir_arbol_en_inorden (parb->pizq); /* imprime subarbol izquierdo */
      printf ("%d ", parb->info);
      imprimir_arbol_en_inorden (parb->pder); /* imprime subarbol derecho */
    }
}
