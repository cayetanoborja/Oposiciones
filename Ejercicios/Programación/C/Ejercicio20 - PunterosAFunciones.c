/***********************************************************************************/
/************************ EJERCICIO PUNTEROS A FUNCIONES 2 C ***********************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************/
/*Implementa un programa que ordene un vector de enteros haciendo uso de una
función de comparación y para intercambiar los datos. Crea un vector de 10
elementos desordenados y muéstralos por pantalla ordenados. Emplea las
siguientes definiciones de las funciones.

     //Función para comparar 2 valores. Retorna 1 si valor1>valor 2 o -1 en otro caso
     int Comparacion (int valor1, int valor2);
     
     //Función para intercambiar el valor de 2 posiciones en un vector.
     void CambiarDatos (int posI, int posJ, int *Vector);
     
     //Función que ordena un vector que recibe un puntero a una función de comparación.
     void Ordenamiento (int (*compara) (int, int), int *Vector, int maximo); */

#include <stdio.h>

int Comparacion (int valor1, int valor2);

void CambiarDatos (int posI, int posJ, int *Vector);

void Ordenamiento (int (*compara) (int, int), int *Vector, int maximo);

int main (){
    int i;
    int Vector [] = {0,6,3,2,1,9,8,7,4,5};
    int (*compara) (int, int); 
    compara = &Comparacion; //el puntero compara apuntará a la función Comparación.
      
    printf ("\n El vector desordenado es: ");
    for (i=0;i<10;i++){
        printf ("[%d] ", Vector[i]);      
    }
    
    Ordenamiento(compara,Vector,10); //Me llevo la dirección de la función Comparacion.
        printf ("\n\n El vector ordenado es: ");
    for (i=0;i<10;i++){
        printf ("[%d] ", Vector[i]);      
    }
    getchar();
}

int Comparacion (int valor1, int valor2){
    if (valor1>valor2){
         return 1;
    }
    else{
         return -1;
    }   
}

void CambiarDatos (int posI, int posJ, int *Vector){
     int auxiliar;
     auxiliar = Vector[posI];
     Vector[posI] = Vector[posJ];
     Vector[posJ] = auxiliar;   
}

void Ordenamiento (int (*compara) (int, int), int *Vector, int maximo){
     int i,j;
     
     for (i=0;i<10;i++){
         for (j=0;j<10;j++){
             if (compara(Vector[i],Vector[j])<0){
                   CambiarDatos(i,j,Vector);
             }
         }
     }   
}
