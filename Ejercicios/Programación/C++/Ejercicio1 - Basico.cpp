/***********************************************************************************/
/****************************** EJERCICIO BASICO 1 C++ *****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Realizar un programa en C++ que pida por teclado el nombre de usuario y su edad, y
finalice mostrando por pantalla su nombre y su edad en formato: "Hola <nombre>,
tienes <edad> años". Emplea para ello el tipo "string" que define C++.*/
   
/***********************************************************************************/
/******************************** LIBRERIAS Y CLASES *******************************/
/***********************************************************************************/   
#include <iostream>
using namespace std; //Esto se pone siempre.

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main (){    
    string Nombre;
    int Edad;
    cout << "Introduzca un Nombre: ";
    cin >> Nombre;
    cout << "Introduzca una Edad: ";
    cin >> Edad;
    cout << "Hola " << Nombre << ", tienes " << Edad << " anos.";
    getchar();
    getchar();
}
