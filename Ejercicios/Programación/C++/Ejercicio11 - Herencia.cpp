/***********************************************************************************/
/***************************** EJERCICIO HERENCIA 4 C++ ****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: En C++ (en otros lenguajes no) se puede dar otro tipo de herencia: la
herencia múltiple, en el que una clase puede derivar de varias clases base.
    
Implementar una clase Profesor que contenga un nombre y la materia que imparte y una
clase investigador con su nombre y su especialidad que investiga. Posteriormente crear
la clase ProfesorUniversitario que herede de las 2 clases anteriores.  
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
using namespace std;

//CLASE PROFESOR.
class Profesor{
      //Atributos.
      private:
              string Nombre;
              string Materia;
      //Métodos.
      public:
             //Constructor por defecto.
             Profesor (){}
             //Constructor que recibe 2 atributos;
             Profesor (const string &Nombre, const string &Materia){
                    this->Nombre = Nombre;
                    this->Materia = Materia;
             }
             //Método de devolución de Nombre.
             const string &getNombre() const{
                    return Nombre;
             }
             //Método de devolución de Materia.
             const string &getMateria() const{
                    return Materia;
             }
};

//CLASE INVESTIGADOR.
class Investigador{
      //Atributos.
      private:
              string Nombren;
              string Especialidad;
      //Métodos.
      public:
             //Constructor por defecto.
             Investigador (){}
             //Constructor que recibe 2 atributos;
             Investigador (const string &Nombre, const string &Especialidad){
                    this->Nombren = Nombre;
                    this->Especialidad = Especialidad;
             }
             //Método de devolución de Nombre.
             const string &getNombre() const{
                    return Nombren;
             }
             //Método de devolución de Materia.
             const string &getEspecialidad() const{
                    return Especialidad;
             }
};

//CLASE PROFESORUNIVERSITARIO.
class ProfesorUniversitario : public Profesor, public Investigador{
      public:
             //Constructor por defecto.
             ProfesorUniversitario (){}
             //Constructor que recibe 3 atributos;
             ProfesorUniversitario (const string &Nombre, const string &Especialidad, const string &Materia) : Profesor (Nombre, Materia), Investigador (Nombre, Especialidad){}
             //Si nos fijamos, maneja la memoria ineficientemente ya que almacena 2 nombres: el del investigador y el del profesor. Hay que tener cuidado.
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    ProfesorUniversitario Profesor1("Manuel", "Maquinas Virtuales", "Tecnologia de Objetos");
    cout <<  Profesor1.Investigador::getNombre() << ", " << Profesor1.getMateria() << ", " << Profesor1.getEspecialidad() << endl;
    //Como tiene 2 nombres, se pone Profesor1.Investigador::getNombre() para obtener un nombre. Si se hubiera puesto Profesor1.getNombre() da error porque existen 2.      
    getchar();    
}
