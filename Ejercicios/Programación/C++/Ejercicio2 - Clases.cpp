/***********************************************************************************/
/****************************** EJERCICIO CLASES 1 C++ *****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: En C se crean estructuras y se acceden a ellas con funciones y/o
procedimientos. En C++ se utilizan clases que son como estructuras y poseen métodos
que son como las funciones de C. Ejemplo:
    
Realizar la implementación de la siguiente clase Punto. A parte, añade un método que 
sume 2 puntos y devuelva otro nuevo la suma de los 2:
   class Punto{
      private:
           float x_;
           float y_;
      public:
           Punto (float = 0, float = 0);
               void mostrar () const; //Visualiza (x,y) en la pantalla.
               void x(float x); //Cambia la coordenada x.
               void y(float y); //Cambia la coordenada y.
               void cambiar (float x, float y); //Cambia ambas coordenadas.
               void transladar(float desplazamiento); //Suma desplazamiento a cada coordenada.
               float x() const; //Devuelve la coordenada X.
               float y() const; //Devuelve la coordenada Y.
       }*/
   
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/   
#include <iostream>

using namespace std; //Esto se pone siempre.

//DEFINIMOS LA CLASE PUNTO.
class Punto{
      //DEFINIMOS LOS ATRIBUTOS.
      private: //Lo normal es declarar los atributos como privado para que no puedan acceder a ellos nadie.
              float x_;
              float y_;
      //DEFINIMOS LOS MÉTODOS.
      public: //Los métodos como públicos, ya que es donde queremos acceder.
             //Declaramos un Constructor. Los constructores tienen el mismo nombre que la clase y se pueden o no declarar, sirven para darles valores inicialmente a la hora de declarar un objeto.
             Punto (float x = 0, float y = 0){
                   this->x_ = x;  //Como x_ y x se llaman distinto no hace falta poner "this" para distinguirlos, si se llamaran igual entonces sí, siendo el this el atributo de la clase.
                   y_ = y;
             }
             //Declaramos un Destructor. Destruyen el objeto.
             ~Punto(){}
             //Método de devolución de la coordenada X. El atributo x_ es privado, así que no se puede acceder poniendo Objeto1.x_ como en C, si fuera público entonces sí. Para acceder a él hay que añadir un método que nos devuelva el valor y se accede llamando a ése método de forma: Objeto1.x().
             float x() const{
                   return x_;
             }
             //Método de devolución de la coordenada Y.
             float y() const{
                   return y_;
             }
             //Método que visualiza (x,y) en la pantalla.
             void mostrar () const {
                  cout << "El valor del punto es: (" << x_ << "," << y_ << ")" << endl;
             }
             //Método modificación de la coordenada X. Tampoco podemos modificar el atributo de forma: Objeto1.x_ = 3 como en C ya que es privado. Se crea un método que recibe un parámetro y lo modifica. Por ejemplo: Objeto1.x(3).   
             void x(float x){
                  x_ = x;
             }
             //Método de modificación de la coordenada Y.     
             void y(float y){
                  y_ = y;
             }
             //Método de modificación de ambas coordenadas.      
             void cambiar (float x, float y){
                  x_ = x;
                  y_ = y;
             } 
             //Método que suma un desplazamiento a cada coordenada.     
             void transladar(float desplazamiento){
                  x_ += desplazamiento;
                  y_ += desplazamiento;
             }
             //Método que sume 2 puntos y devuelve la suma.
             Punto suma (Punto a, Punto b){                  
                   x_ += a.x_ + b.x_;
                   y_ += a.y_ + b.y_;
             }
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main (){    

     Punto Punto1(3,2); //Creamos el objeto Punto1 de la clase Punto utilizando el constructor y dándole valores iniciales 3 y 2.
     Punto Punto2(10,20);
     Punto Punto3(0,0);
     Punto1.mostrar();  //Llama al método mostrar del punto1.
     Punto1.x(5); //Llama al método x(float x), que hace que Punto1.x = 5.
     Punto1.y(6);
     Punto1.mostrar();
     Punto1.cambiar (6,7);
     Punto1.mostrar();
     Punto1.transladar(5);
     Punto1.mostrar();
     Punto3.suma(Punto1, Punto2);
     Punto3.mostrar();
     getchar();
}
