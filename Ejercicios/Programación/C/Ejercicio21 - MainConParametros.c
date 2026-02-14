/***********************************************************************************/
/************************ EJERCICIO MAIN CON PARÁMETROS 1 C ************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Escribe un programa que reciba un número variable de argumentos en la función "main"
y que los sume y los multiplique. Por ejemplo, una invocación al programa podría ser:
      C:\> Operaciones 1 2 3 4 5 6 7
      La suma total es: 28
      El producto es: 5040 */
      
#include <stdio.h>

int main (int argc, int *argv[]){  //"argc" es el número de argumentos, "*argv" es un puntero a un array de elementos que reciba.
     
     int i, suma, producto;
     
     if (argc <= 1){ //Si los argumentos son menores o iguales que 1.
              return 0;
     }
     else //Si recibe al menos 2 argumentos.
     {
          suma = atoi(argv[1]); // suma será igual a el valor del argumento 1 transformado de caracter a entero.
          producto = suma;
          for (i=2;i<argc;i++){  //Desde el segundo argumento porque el primero ya lo pusimos.
              suma += atoi(argv[i]);
              producto *= atoi(argv[i]);
          }
          printf ("\n La suma total es: %d", suma);
          printf ("\n\n El producto total es: %d", producto);
          getchar();
     }  
}
