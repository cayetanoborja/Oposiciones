/***********************************************************************************/
/************************* EJERCICIO GESTIÓN DE ERRORES C++ ************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: La gestión de errores está basada en excepciones que señalan errores y
se lanzan (throw) hasta que se capturan (catch, dentro de un bloque try). Ejemplo:
    
Implementar un programa que pida por pantalla un dividendo, un divisor y una cadena
de caracteres. El programa debe gestionar los errores de división entre 0 y que la
cadena insertada no sea vacía.
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
using namespace std;

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    int Dividendo, Divisor;
    string Nombre;
    //Bloque try (el programa normal).
    try{
        cout << "Introduzca el dividendo: ";
        cin >> Dividendo;
        cout << endl <<"Introduzca el divisor: ";
        cin >> Divisor;
        //Comprobamos que el divisor no sea 0.
        if ( Divisor == 0){
             throw 0; //Es 0, lanzamos el error.
        }
        else{
             cout << endl << "La division es: " << Dividendo/Divisor;
             getchar();
             getchar();
        }
        cout << endl <<"Introduzca tu nombre: ";
        cin >> Nombre;
        //Comprobamos que no esté vacío.
        if (Nombre.empty()){
             throw Nombre; //Lanzamos el error.
        }
        else{
             cout << endl << "Tu nombre es: " << Nombre;
             getchar();
             getchar();
        }
    }
    //Bloque Catch. Captura los errores si se han lanzado con throw.
    //Si el error que llegó es un entero.
    catch (int error){
          cerr << endl << "Es necesario un divisor distinto de 0.";
          getchar();
          getchar();
    }
    //Si el error que llegó es una cadena
    catch (const string &error){
          cerr << endl << "Es imposible que no tengas nombre.";
          getchar();
          getchar();
    }
}
