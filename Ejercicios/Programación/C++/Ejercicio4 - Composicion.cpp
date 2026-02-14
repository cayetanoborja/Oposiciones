/***********************************************************************************/
/*************************** EJERCICIO COMPOSICIÓN 2 C++ ***************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Implementar una clase Cola. Una cola es una lista (o conjunto) donde el primer
elemento que se añade es el primero que sale, es decir, se van añadiendo por
detrás y se van eliminando desde el principio. Piensa en la cola del cine.
Queremos hacer una cola de personas, para ello vamos a utilizar un vector donde
vamos a guardar un String, y una clase Cola con los siguientes métodos.
      - Un constructor por defecto.
      - void IntroducirEnCola(String nombre), que recibe una cadena y la mete al final de la lista.
      - void SacarDeCola(), que visualiza el primer nombre de la lista y lo elimina.
      - void ListarCola(), visualiza los nombres de la cola.

Crear un programa principal, con un menú para escoger los distintos métodos de
la clase Cola. Ejemplo de funcionamiento:
         1. Añadimos los siguientes nombres: Ana, Juan, Pepe, Carlos
         2. Listamos la cola: Ana, Juan, Pepe, Carlos
         3. Sacamos de la cola: Ana
         4. Listamos la cola: Juan, Pepe, Carlos
         5. Sacamos de la cola: Juan
         6. Listamos la cola: Pepe, Carlos
         7. Añadimos a la cola: María.
         8. Listamos la cola: Pepe, Carlos, María.*/

/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
#define ElementosVector 10
using namespace std;

//IMPLEMENTAMOS CLASE PERSONA
class Persona{
      //ATRIBUTOS.
      private:
              string Nombre_;
      //MÉTODOS      
      public:
             //Constructor por defecto.
             Persona(){}
             //Destructor.
             ~Persona(){}
             //Metodo de devolución de nombre.
             string Nombre(){
                    return Nombre_;
             }
             //Metodo de modificación de nombre.
             void IntroducirNombre(const string &n){  //Se podría escribir: "void IntroducirNombre(string n)" pero puede ocasionar problemas, cuando son cadenas es preferible ponerlo así.
                    Nombre_ = n;
             }
};

//IMPLEMENTAMOS CLASE COLA
class Cola{
      //ATRIBUTOS
      private:
             Persona Vector[ElementosVector];     
      //MÉTODOS.        
      public:
             //Constructor por defecto.
             Cola (){}
             //Destructor.
             ~Cola (){}
             //Método introducir.
             void IntroducirEnCola(const string &nombre){
                  int i = 0;
                  while (Vector[i].Nombre() != ("")){ //Accede al método Nombre de la clase Persona para leer el nombre.
                        i++;   
                  } 
                  Vector[i].IntroducirNombre(nombre); //Accede al método IntroducirNombre de la clase Persona para escribir el nombre.
             };
             //Método Extraer.
             void SacarDeCola(){
                  int i = 0;
                  if (Vector[0].Nombre() == ("")){
                        cout << endl << "La cola no contiene elementos." << endl;      
                  }
                  else{
                       cout << endl << "Se ha extraido [" << Vector[0].Nombre() << "]" << endl; 
                       while (Vector[i].Nombre() != ("")){
                             Vector[i].IntroducirNombre(Vector[i + 1].Nombre()); //Llama al método IntroducirNombre con el atributo que lea del método nombre.
                             i++;
                       }    
                  }
                  getchar();
                  getchar(); 
             }
             //Método mostrar.
             void ListarCola(){
                  int i = 0;
                  if (Vector[0].Nombre() == ("")){
                         cout << endl << "La cola no contiene elementos." << endl;
                  }
                  else
                  {       
                          cout << endl << "La cola contiene:";
                          while (Vector[i].Nombre() != ("")){
                                cout << " [" << Vector[i].Nombre() << "]"; 
                                i++;   
                          }
                          cout << endl;
                  }
                  getchar();
                  getchar();                     
             };   
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    Cola Cola1;
    string nombre;
    int opcion;
    
    while (opcion != 4){
          cout << "Opcion 1: Insertar elementos." << endl;
          cout << "Opcion 2: Sacar de la cola." << endl;
          cout << "Opcion 3: Listar Cola." << endl;
          cout << "Opcion 4: Salir." << endl << endl;
          cout << "Elige opcion: ";
          cin >> opcion;
          switch (opcion){
                 //CASO 1: Insertamos.
                 case 1:
                      cout << endl << "Introduzca el nombre: ";
                      cin >> nombre;
                      Cola1.IntroducirEnCola(nombre);
                      cout << endl << "Elemento insertado." << endl;
                      getchar();
                      getchar();
                 break;
                 //CASO 2: Extraemos.
                 case 2:
                      Cola1.SacarDeCola();
                 break;
                 //CASO 3: Listamos.
                 case 3:
                      Cola1.ListarCola();
                 break;
                 //CASO 4: Salimos.
                 case 4:
                 break;
                 //CUALQUIER OTRO CASO: Mensaje.
                 default:
                         cout << endl << "Opcion invalida, intentelo de nuevo." << endl;
                         getchar();
                         getchar();
                 break;
          }  
    } 
}
