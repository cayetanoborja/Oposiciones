/***********************************************************************************/
/************************* EJERCICIO GESTIÓN DE ERRORES C++ ************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: La manera de gestionar los errores en el ejercicio anterior no es el
mejor uso que se puede hacer. Lo más correcto es definir clases de excepciones
para poder lanzarlas instanciadas (en lugar de primitivos como int) con runtime_error.
    
Implementar el ejercicio anterior haciendo uso de esta manera.
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

//CLASE ERRORDIVISONPORCERO.
class ErrorDivisionPorCero : runtime_error{
      public:
             ErrorDivisionPorCero (char *mensaje) : runtime_error (mensaje){}
};
//CLASE ERRORCADENAVACIA.
class ErrorCadenaVacia : runtime_error{
      public:
             ErrorCadenaVacia (char *mensaje) : runtime_error (mensaje){}
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
   // int Dividendo, Divisor;
    string Nombre;
    //Bloque try (el programa normal).
    try{
        int *Dividendo = new int;
        int *Divisor = new int;
        cout << "Introduzca el dividendo: ";
        cin >> *Dividendo;
        cout << endl <<"Introduzca el divisor: ";
        cin >> *Divisor;
        //Comprobamos que el divisor no sea 0.
        if ( *Divisor == 0){
             throw ErrorDivisionPorCero (" El divisor no puede ser 0." ); //Es 0, lanzamos el error.
        }
        else{
             cout << endl << "La division es: " << *Dividendo / *Divisor;
             getchar();
             getchar();
        }
        cout << endl <<"Introduzca tu nombre: ";
        cin >> Nombre;
        //Comprobamos que no esté vacío.
        if (Nombre.empty()){
             throw ErrorCadenaVacia (" Es imposible que no tengas nombre." ); //Lanzamos el error.
        }
        else{
             cout << endl << "Tu nombre es: " << Nombre;
             getchar();
             getchar();
        }
    }
    //Bloque Catch. Captura los errores si se han lanzado con throw.
    catch (const ErrorDivisionPorCero &error){
          cerr << endl << "ERROR: " << error.what() << endl;
          getchar();
          getchar();
    }
    catch (const ErrorCadenaVacia &error){
          cerr << endl << "ERROR: " << error.what();
          getchar();
          getchar();
    }
    catch (const exception &error){
          cerr << endl << "Error inesperado: " << error.what();
          getchar();
          getchar();
    }
    catch (...){
          cerr << endl << "Error fatal inesperado.";
          getchar();
          getchar();
    }
}
