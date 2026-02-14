/***********************************************************************************/
/***************************** EJERCICIO C ESTRUCTURAS *****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa en C que contenga los siguientes elementos:
      1) Una estructura llamada Titular que represente clientes con su nombre,
         apellidos, dirección y dni.
      2) Una estructura llamada CuentaCorriente que tenga como campos: 2
         titulares, un número de cuenta (20 caracteres) y el saldo de la
         cuenta(double).
      3) Crear la función rellenarCuenta que devuelva como resultado una cuenta
         cuyos datos deben leerse por teclado, pero teniendo en cuenta que: 
         Puede haber uno o 2 titulares (al menos uno), el número de cuenta 
         deben de ser exáctamente 20 números y el saldo debe ser positivo.
      4) Crear la función cambiarSaldo que reciba una cuenta y un valor decimal
         y cambie el saldo de la cuenta que coincida con el valor del número
         decimal.*/

//Estructura Titular.
typedef struct{
        char DNI[9];
        char Nombre[25];
        char Apellidos[30];
        char Direccion[50];
}Titular;

//Estructura CuentaCorriente.
typedef struct{
        Titular Titular1, Titular2;
        char NumCuenta[20];
        double Saldo;
}CuentaCorriente;

//Función que pide datos y rellena una cuenta.
CuentaCorriente rellenarCuenta(CuentaCorriente Cuenta);

//Función que pide datos por teclado y rellena un titular.
Titular rellenarTitular(Titular Titular); 

//Función que muestra por pantalla los datos de la cuenta y sus titulares.
void mostrarDatos (CuentaCorriente Cuenta);

//Función que muestra por pantalla los datos de un titular.
void mostrarTitular (Titular Titular);

//Procedimiento para cambiar el saldo de una cuenta.
void cambiarSaldo (CuentaCorriente *Cuenta, double SaldoNuevo);

         
#include <stdio.h>

int main (){
    int opcion;
    CuentaCorriente Cuenta;
    double SaldoNuevo;
    
    while (opcion != 4){
          printf ("\n Opcion 1: Insertar una cuenta corriente.");
          printf ("\n Opcion 2: Ver datos de la cuenta y sus titulares.");
          printf ("\n Opcion 3: Cambiar saldo.");
          printf ("\n Opcion 4: Salir.");
          printf ("\n\n Elige una opcion: ");
          scanf ("%d", &opcion);
          switch (opcion){
                 case 1: //Insertamos una cuenta corriente.
                      Cuenta = rellenarCuenta(Cuenta);      
                 break;
                 case 2: //Ver datos de la cuenta y sus titulares.
                      mostrarDatos (Cuenta);
                 break;
                 
                 case 3: //Cambiar el saldo de la cuenta
                      printf ("\n Inserte el saldo nuevo: ");
                      scanf ("%lf", &SaldoNuevo);
                      cambiarSaldo (&Cuenta, SaldoNuevo);
                 break;
                 
                 case 4: //Salimos del programa.
                 break;
                 
                 default: //Cualquier otra opción.
                      printf ("\n Opcion invalida, vuelve a intentarlo.\n");
                      getchar();
                      getchar();
                 break;       
          }        
    }    
}

//FUNCIONES
//Función que pide datos y rellena una cuenta.
CuentaCorriente rellenarCuenta(CuentaCorriente Cuenta){
     int titulares = 0;
     int NumCaracteresCuenta = 0;
     
     //Pedimos el número de cuenta.
     while (NumCaracteresCuenta != 20){
           printf ("\n Escribe el numero de cuenta (20 digitos): ");
           scanf(" %[^\n]", Cuenta.NumCuenta);
           NumCaracteresCuenta = strlen(Cuenta.NumCuenta); //Contamos los dígitos del número de cuenta.
           if (NumCaracteresCuenta != 20){
                     printf ("\n Error. El numero de cuenta ha de ser de 20 digitos.\n");
                     getchar();           
           }
     }
     
     //Pedimos el saldo de la cuenta.
     Cuenta.Saldo = -1;
     while (Cuenta.Saldo < 0){
           printf ("\n Escribe el saldo de la cuenta: ");
           scanf ("%lf", &Cuenta.Saldo);
           if (Cuenta.Saldo < 0){
                  printf ("\n Error. El saldo ha de ser positivo.\n");
                  getchar();
                  getchar();
           } 
     }
     
     //Pedimos cuántos titulares va a tener esa cuenta.           
     while ((titulares > 2) || (titulares < 1)){
           printf ("\n De cuantos titulares va a ser la cuenta corriente?: ");
           scanf ("%d", &titulares); 
     }
     printf ("\n DATOS DEL TITULAR 1 \n");
     Cuenta.Titular1 = rellenarTitular(Cuenta.Titular1);  //Llama a una función para rellenar los datos del titular. 
     if (titulares == 2){
           printf ("\n DATOS DEL TITULAR 2 \n");
           Cuenta.Titular2 = rellenarTitular(Cuenta.Titular2);      
     }
     else{ //Si no hay 2 titulares, pongo una marca al DNI del titular 2.
          strcpy(Cuenta.Titular2.DNI,"NULO");
     }    
     return (Cuenta);                
}

//Función que pide datos por teclado y rellena un titular.
Titular rellenarTitular(Titular Titular){
               
        printf ("\n Introduce el DNI: ");
        scanf(" %[^\n]", Titular.DNI);
        printf ("\n Introduce el Nombre: ");
        scanf(" %[^\n]", Titular.Nombre);
        printf ("\n Introduce los Apellidos: ");
        scanf(" %[^\n]", Titular.Apellidos);
        printf ("\n Introduce la Direccion: ");
        scanf(" %[^\n]", Titular.Direccion);
        return (Titular);              
}

//Función que muestra por pantalla los datos de la cuenta.
void mostrarDatos (CuentaCorriente Cuenta){
     printf ("\n DATOS DE LA CUENTA \n");
     printf ("\n El numero de cuenta es: %s", Cuenta.NumCuenta);
     printf ("\n El saldo de la cuenta es: %lf", Cuenta.Saldo);
     printf ("\n\n TITULARES \n");
     printf ("\n Titular 1:\n");
     mostrarTitular (Cuenta.Titular1);
     if (strcmp("NULO",Cuenta.Titular2.DNI) != 0){ //Si el DNI del titular 2 no es nulo.
           printf("\n\n Titular 2:\n");
           mostrarTitular (Cuenta.Titular2);
     } 
     printf ("\n");
     getchar();
     getchar();
}

//Función que muestra por pantalla los datos de un titular.
void mostrarTitular (Titular Titular){
     printf ("\n DNI: %s", Titular.DNI);
     printf ("\n Nombre : %s", Titular.Nombre);     
     printf ("\n Apellidos: %s", Titular.Apellidos);
     printf ("\n Direccion: %s", Titular.Direccion);       
}

//Función que cambia el saldo de la cuenta.
void cambiarSaldo (CuentaCorriente *Cuenta, double SaldoNuevo){
     (*Cuenta).Saldo = SaldoNuevo;   
}
