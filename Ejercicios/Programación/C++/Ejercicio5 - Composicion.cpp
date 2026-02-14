/***********************************************************************************/
/*************************** EJERCICIO COMPOSICIÓN 3 C++ ***************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Queremos crear un programa para gestionar una agenda de números de teléfono.
Para ello vamos a crear la clase Contacto, donde vamos a guardar el nombre del
contacto y su número de teléfono. A continuación vamos a crear una clase Agenda,
que va a representar un conjunto de contactos. Para ello vamos a utilizar un
vector. La clase Agenda tendrá los siguientes métodos:
        - addContacto: Pide por teclado un contacto y lo añade a la agenda.
        - delContacto: Pide un nombre y borra todos los contactos con ese nombre.
        - listContacto: Lista todos los contactos.
        - findContacto: Pide una cadena y muestra todos los contactos que comiencen con dicha cadena.
Hacer un programa principal, con un menú que permita gestionar todas las operaciones
de nuestra agenda.*/

/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/
#include <iostream>
#define NumContactos 10
using namespace std;

//CLASE CONTACTO.
class Contacto{
      //Atributos.
      private:
              string Nombre;
              int Telefono;
      //Métodos.        
      public:
             //Constructor por defecto.
             Contacto (){}
             //Destructor.
             ~Contacto (){}
             //Método de devolución del nombre.
             string getNombre(){
                    return Nombre;
             }
             //Método de devolución del telefono.
             int getTelefono(){
                    return Telefono;
             }
             //Método de modificación de ambos atributos.
             void IntroducirContacto (const string &Nombre, int Telefono){
                  this->Nombre = Nombre; //Se llaman igual, el que tiene this es para referirnos al atributo, el que no es el parámetro que recibe.
                  this->Telefono = Telefono;  
             }
};

//CLASE AGENDA.
class Agenda{
      //Atributos.
      private:
              Contacto Vector[NumContactos]; //Un vector de Contactos de NumContactos elementos.
      //Métodos.        
      public:
             //Constructor por defecto.
             Agenda (){}
             //Destructor.
             ~Agenda(){}
             //Método de devolución.
             Contacto getVector(int i){
                      return Vector[i];          
             }
             //Método que permite introducir un Nombre en la agenda.
             void addContacto (){
                  string Nombre;
                  int Telefono;
                  cout << endl << "Introduce el nombre del contacto: ";
                  cin >> Nombre;
                  cout << endl << "Introduce el numero de telefono: ";
                  cin >> Telefono;
                  int i = 0;
                  while (Vector[i].getNombre() != ("")){ //Buscamos un hueco libre y nos posicionamos.
                        i++;
                  }
                  Vector[i].IntroducirContacto(Nombre, Telefono);
                  cout << endl << "Contacto introducido." << endl;
                  getchar();
                  getchar();
             }
             //Método que borra los contactos de un Nombre de la agenda.
             void delContacto (){
                  string Nombre;
                  int i = 0, j = 0, eliminado = 0;
                  
                  if (Vector[0].getNombre() == ("")){
                          cout << endl << "La agenda no contiene contactos.";                                       
                  }
                  else
                  {
                          cout << endl << "Introduce el nombre del contacto: ";
                          cin >> Nombre;
                          while (Vector[i].getNombre() != ("")){ 
                                if (Vector[i].getNombre() == Nombre){
                                        j = i;
                                        //Movemos todos los posteriores una posición atrás sobreescribiendo el contacto a borrar.
                                        while (Vector[j].getNombre() != ("")){
                                              Vector[j].IntroducirContacto(Vector[j + 1].getNombre(), Vector[j + 1].getTelefono());
                                              j++;  
                                        }
                                        eliminado += 1;
                                        i--;
                                }
                                i++; 
                          }
                          if (eliminado > 0){
                                cout << endl << "Se han eliminado " << eliminado << " contactos.";        
                          }
                          else{
                                cout << endl << "No existen contactos con ese nombre.";
                          }
                  }
                  getchar();
                  getchar();
                  cout << endl;  
             }
             //Método que lista todos los contactos de la agenda.
             void listContacto(){
                  int i = 0;
                  if (Vector[0].getNombre() == ("")){
                       cout << endl << "La agenda no contiene contactos.";
                  }
                  else{
                       while (Vector[i].getNombre() != ("")){
                             cout << endl << "Contacto numero " << i + 1 << ": Nombre: " << Vector[i].getNombre() << ", telefono: " << Vector[i].getTelefono();
                             i++;
                       }
                  } 
                  getchar();
                  getchar(); 
                  cout << endl;       
             }
             //Método que muestra todos los contactos que comiencen por una cadena.
             void findContacto(){
                  int i = 0, j, encontrado = 0, existe = 0;
                  string Nombre;
                  
                  if (Vector[0].getNombre() == ("")){
                           cout << endl << "La agenda no contiene contactos.";                                       
                  }
                  else
                  {
                           cout << endl << "Introduce el nombre por donde empieza el contacto: ";
                           cin >> Nombre;
                           while (Vector[i].getNombre() != ("")){
                                 encontrado = 0;
                                 for (j=0; j<Nombre.length(); j++){ //Desde 0 hasta el tamaño de la cadena.
                                        if (Nombre[j] != Vector[i].getNombre()[j]){ //Comparamos el caracter j de la cadena con el del nombre.
                                               encontrado += 1;
                                        }
                                 }
                                 if (encontrado == 0){ //Si encontrado = 0 es porque los caracteres coinciden.
                                        cout << endl << "Nombre: " << Vector[i].getNombre() << ", telefono: " << Vector[i].getTelefono();
                                        existe = 1;     
                                 }
                                 i++; 
                           }
                           if (existe == 0){
                                 cout << endl << "No existen contactos que empiecen por ese nombre.";
                           }         
                  }
                  getchar();
                  getchar();
                  cout << endl;
             }
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    int opcion, Telefono;
    string Nombre;
    Agenda Agenda;
    
    while (opcion != 5){
          cout << "Opcion 1: Introducir un contacto en la agenda." << endl;
          cout << "Opcion 2: Borrar contactos de la agenda." << endl;
          cout << "Opcion 3: Listar contactos de la agenda." << endl;
          cout << "Opcion 4: Buscar contacto en la agenda." << endl;
          cout << "Opcion 5: Salir del programa." << endl << endl;
          cout << "Escoge una opcion: ";
          cin >> opcion;
          switch (opcion){
                 //Caso 1: Introducir un contacto.
                 case 1:
                      Agenda.addContacto();
                 break;
                 //Caso 2: Borrar contacto.
                 case 2:
                      Agenda.delContacto();
                 break;
                 //Caso 3: Listar agenda.
                 case 3:
                      Agenda.listContacto();
                 break;
                 //Caso 4: Buscar contacto.
                 case 4:
                      Agenda.findContacto();
                 break;
                 //Caso 5: Salir del programa.
                 case 5:
                 break;
                 //Caso Cualquiera: Muestra error.
                 default:
                         cout << endl << "Opcion invalida, vuelve a intentarlo." << endl;
                         getchar();
                         getchar();
                 break;           
          }   
    }  
}
