/***********************************************************************************/
/******************************* EJERCICIO C PUNTEROS ******************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Modificar el programa anterior para que la función devuelva
punteros al mayor y el menor valor del array*/

# include <stdio.h>
# define TAMANO 5

//DECLARO LA FUNCIÓN.	
void Calcular(float **mayor, float **menor, float *vector, int tamano);

//EMPEZAMOS EL PROGRAMA.
int main()
{ 
    float *mayor, *menor; //Creo los punteros mayor y menor.
    float Array[] = {44,3,89,19,192};  //Creamos un vector cualquiera.
    Calcular (&mayor, &menor, Array, TAMANO);
    printf ("\n El mayor es: %f", *mayor);
    printf ("\n El menor es: %f", *menor);
    getchar();
}

//EJECUTA LA FUNCIÓN.
void Calcular(float **mayor, float **menor, float *vector, int tamano){
     int i;
     *menor = &vector[0];
     *mayor = &vector[0];
     
     for (i=1;i<tamano;i++){ //No es necesario empezar desde el primer elemento, ya se les asignó el valor del primer elemento.
         //La variable "Menor" tomará el valor del vector si la del vector es menor, sino no.
         if (**menor > vector[i]){
                *menor = &vector[i];
         }
         //La variable "Mayor" tomará el valor del vector si la del vector es mayor, sino no.
         if (**mayor < vector[i]){
                *mayor = &vector[i];
         }             
     }
}
