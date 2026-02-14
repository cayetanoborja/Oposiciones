/***********************************************************************************/
/************************ EJERCICIO MAIN CON PARÁMETROS 2 C ************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Escribe un programa que reciba como parámetros una cadena indicando el tipo de
dato que se va a introducir en segundo lugar y lo indique por pantalla. Por
ejemplo, una invocación al programa podría ser:
      C:\> ejercicio int 223
      El parámetro es de tipo entero y su valor es: 223.
      C:\> ejercicio float 2.456
      El parámetro es de tipo flotante y su valor es: 2.456.
      C:\> ejercicio char a
      El parámetro es de tipo carácter y su valor es: a.*/
      
#include <stdio.h>

int main (int argc, int *argv[]){  
     if (argc != 3){
              return;
     }
     else{
          if (strcmp (argv[1], "int") == 0){ //Si argv[1] = int     
                     printf ("\n El parametro es de tipo entero y su valor es: %d", atoi(argv[2]));
          }  
          if (strcmp (argv[1], "float") == 0){ 
                     printf ("\n El parametro es de tipo flotante y su valor es: %f", atof(argv[2]));
          }
          if (strcmp (argv[1], "char") == 0){    
                     printf ("\n El parametro es de tipo caracter y su valor es: %c", argv[1][0]); //Si es caracter también hay que poner el 0.
          }                          
          getchar();           
     }
}
