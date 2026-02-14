 
   /**
    
     Ejercicio para probar la resta de punteros.
     Una vez probados parece que la resta devuelve unidades...
     ...del tipo base y no bytes. 
     No se intenta mejorar nada ya que igual de eficiente debe ser ...
     ... recorrer un vector con un ķndice que con un puntero. Solo es ...
     ... para probar que la aritmética de punteros no solo funciona ...
     ... con las sumas sino también con las restas.
     En una de las funciones de paso se comprueba que ...
     ... como era de esperar el posdecremento (--) también funciona.
     
    **/

# include <stdlib.h>
# include <stdio.h>

# define MAX_V 10


   
/* Prueba con enteros */
void prueba_enteros(){
     int *a, *p; // a contendra la matriz y p el puntero que la recorrera
     int i;
     a = (int*)malloc(MAX_V*sizeof(int));  // crea el vector dinamico
     for (i=0;i<MAX_V;i++){a[i]=(i);} // lo rellena con los pares

     // muestra el resultado recorriendo con el puntero p
     // no es necesario un ķndice ya que p-a resta ...
     // ...en función del tipo base del vector, en este caso enteros
	 
     for (p=a;p-a<MAX_V;p++) // muesta el contenico recorriendolo con p
             printf("*p=%d\n", *p); 

     free(a); // libera el espacio
     a=NULL;  // no seria necesario ya que al finalizar la funcion...
              // ...la vriable puntero a desaparecerį igual que p
     }
     
/* Prueba con una estructura */
void prueba_estructura(){
     struct punto{
            int x,y;
            };
     struct punto *a, *p; // a contendrį la matriz y p el puntero que la recorrerį
     int i;
     // crea el vector dinįmico
     a = (struct punto *)malloc(MAX_V*sizeof(struct punto));  
     
     for (i=0;i<MAX_V;i++){
         a[i].x=i;
         a[i].y=i;
         } // lo rellena 
     // muestra el resultado recorriendo con el puntero p
     // no es necesario un ķndice ya que p-a resta...
     // ...en función del tipo base del vector, en este caso struct punto
     for (p=a;p-a<MAX_V;p++) // muesta el contenico recorriendolo con p
             printf("*p=%d,%d\n", p->x, p->y); 
     free(a); // libera el espacio
     a=NULL;  // no seria necesario ya que al finalizar la funcion...
              // ...la vriable puntero a desaparecerį igual que p
     }

/* Prueba con una estructura  de nuevo*/
/* llendo un poco mįs lejos podemos quitar la i incluso...
   ...del bucle que rellena el vector, utilizando el puntero p para
   ...rellenarlo. Observar diferencia entre el bucle de relleno...
   ...de este procedimiento y el del anterior */
void prueba_estructura_2(){
     struct punto{
            int x,y;
            };
     struct punto *a, *p; // a contendrį la matriz y p el puntero que la recorrerį
     
     a = (struct punto *)malloc(MAX_V*sizeof(struct punto));  // crea el vector dinįmico
     for (p=a;(p-a)<MAX_V;p++){
         a[p-a].x=(p-a);
         a[p-a].y=(p-a);
         } // lo rellena 
     // muestra el resultado recorriendo con el puntero p
     // no es necesario un ķndice ya que p-a resta ...
     // ...en función del tipo base del vector, en este caso struct punto
     printf("Incrementando el puntero p++ desde dirección base\n");
     for (p=a;p-a<MAX_V;p++) // muesta el contenico recorriendolo con p
             printf("*p=%d,%d\n", p->x, p->y); 
     // ya que estamos comprobamos que el decremento también funciona
     printf("Decrementando el puntero p-- hasta la dirección base\n");                     
     for (p=a+(MAX_V-1);p-a>=0;p--) // muesta el contenico recorriendolo con p
             printf("*p=%d,%d\n", p->x, p->y); 
     free(a); // libera el espacio
     a=NULL;  // no seria necesario ya que al finalizar la funcion ...
              // ...la vriable puntero a desaparecerį igual que p
     }
      
int main() {
    printf("\nPrueba con enteros..........\n");
    prueba_enteros();
    printf("\nPrueba con estructuras.........\n");
    prueba_estructura();
        printf("\nSegunda prueba con Estructura y decremento.\n");
    prueba_estructura_2();
    printf("\n\n");
    }
