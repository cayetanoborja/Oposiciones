/***********************************************************************************/
/******************************* EJERCICIO C PUNTEROS ******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear una función que reciba un puntero a un array, su tamaño y un número
que permita desplazar el array hacia la derecha el número de posiciones
que indique el número, de modo que los números de la derecha aparezcan
por la izquierda*/

# include <stdio.h>
# define TAMANO 10
# define NUMERO 3

void Rotacion(int *array, int tamano, int numero);

int main()
{
    int i;
    int Array[TAMANO];  //Crea un vector de tamaño TAMANO
    for (i=0; i<TAMANO; i++){  //Asigna el valor de i en cada posición del array.
        Array[i] = i;
    }
    
    //Mostramos el array original.
    printf ("\n El array original es:");
    for (i=0;i<TAMANO;i++){
        printf (" [%d]", Array[i]);    
    }
    
    //Desplazamos el array.    
    Rotacion (Array, TAMANO, NUMERO);
    
    //Mostramos el array desplazado.
    printf ("\n\n Desplazado %d posiciones es: ", NUMERO);    
    for (i=0;i<TAMANO;i++){
        printf (" [%d]", Array[i]);    
    }
    getchar();
}


//LO DE ATRÁS ES SOLO PARA PROBAR QUE FUNCIONA, LO QUE REALMENTE SE PIDE EN EL EJERCICIO ES LO SIGUIENTE:
void Rotacion(int *array, int tamano, int numero){
     int ArrayAuxiliar[tamano];
     int i;
     
     //Copiamos el array en un array auxiliar de forma que los 2 sean iguales.
     for (i=0; i<tamano; i++){
         ArrayAuxiliar[i] = array[i];  
     }
     
     //Copiamos en array el array auxiliar desplazado.
     for (i=0; i<numero;i++){
         array[i] = ArrayAuxiliar[i+(tamano-numero)];
     }
          
     for (i=numero; i<tamano; i++){
         array[i] = ArrayAuxiliar[i-numero];    
     }
}
