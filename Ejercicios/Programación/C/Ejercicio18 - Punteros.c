/***********************************************************************************/
/******************************* EJERCICIO C PUNTEROS ******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
/Crear un array de 50 números aleatorios y después un array de 50 punteros donde cada 
uno apunte a los números anteriores.*/

# include <stdio.h>
# include <stdlib.h>
# include <time.h> //Esta librería es para el srand (no siempre hace falta).

int main()
{
    srand (time(NULL)); //Si no hacemos esto, el número aleatorio de rand() será siempre el mismo. Con esto toma como referencia la hora y así cada vez cambia de verdad.
    int i, VectorNumeros[50], *VectorPunteros[50];
    
    for (i=0; i<50;i++){
        VectorNumeros[i] = rand() % 200; //Introducir un número aleatorio entre el 0 y el 200.
        VectorPunteros[i] = &VectorNumeros[i];
    }
 
    for (i=0; i<50;i++){
        printf ("[%d]", *VectorPunteros[i]);
    }
    getchar();
}
