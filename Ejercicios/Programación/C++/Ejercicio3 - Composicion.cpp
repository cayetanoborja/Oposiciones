/***********************************************************************************/
/*************************** EJERCICIO COMPOSICIÓN 1 C++ ***************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: Composición es cuando un atributo de una clase tiene un tipo de otra clase.
Por ejemplo: En el ejercicio anterior se vió la clase punto, una clase rectángulo
tiene como atributos 4 atributos de tipo Punto. Ejemplo:

Realizar la implementación de la clase Rectángulo que contiene cuatro puntos
para definir sus vértices. Estos puntos deben ser atributos dinámicos, es decir,
cada vértice es un puntero a un objeto de tipo punto. Debe haber un método
"mostrar" que muestre las coordenadas del rectángulo por pantalla. La clase
rectángulo debe disponer de un constructor por defecto y otro que reciba cuatro
puntos como parámetros. Utiliza el siguiente código para probar que funciona:
         int main()
         {
             Rectangulo r1;
             Rectangulo r2(2,3);
             Punto p1(1,1), p2(2,1), p3(2,3), p4(1,3);
             Rectangulo r3(p1,p2,p3,p4);
             r1 = r2;
             r1.mostrar();
             r2.mostrar();
         }*/
   
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/   
#include <iostream>

using namespace std;      

//DEFINIMOS LA CLASE PUNTO.
class Punto{
      //DEFINIMOS LOS ATRIBUTOS.
      private:
              float x_;
              float y_;
      //DEFINIMOS LOS MÉTODOS.
      public:
             //Constructor.
             Punto (float x = 0, float y = 0){
                   x_ = x;
                   y_ = y;
             }
             //Destructor.
             ~Punto(){}
             //Método de devolución de la coordenada X.
             float x() const{
                   return x_;
             };
             //Método de devolución de la coordenada Y.
             float y() const{
                   return y_;
             };
             //Método que visualiza (x,y) en la pantalla.
             void mostrar () const {
                  cout << "(" << x_ << "," << y_ << ") ";
                  }
             //Método modificación de la coordenada X.     
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
             //Método que devuelve la distancia entre dos coordenadas de un punto.
             float distancia (Punto) const{
                   //hacerlo luego.
             }
             //Método que sume 2 puntos y devuelve la suma.
             Punto suma (Punto a, Punto b){                  
                   x_ += a.x_ + b.x_;
                   y_ += a.y_ + b.y_;
             }
};

//DEFINIMOS LA CLASE RECTANGULO.
class Rectangulo
{
      //DEFINIMOS LOS ATRIBUTOS.
      private:
              Punto *p1, *p2, *p3, *p4; //p1 es un puntero de tipo Punto.
      //DEFINIMOS LOS MÉTODOS.
      public:
             //Constructor por defecto. Quiere decir que le pone el valor 0 a todos sus atributos.
             Rectangulo (){}
             //Constructor cuando recibe 2 atributos.
             Rectangulo (float x, float y){
                  p1 = new (nothrow) Punto; //Como son punteros, creamos el nodo al que apunta, si no lo fueran no hace falta.
                  p2 = new (nothrow) Punto; //El nothrow no es necesario, se pone para que si no hay memoria suficiente sea nulo.
                  p3 = new (nothrow) Punto;
                  p4 = new (nothrow) Punto;
                  Punto pp1(x,y);
                  Punto pp2(0,0);
                  Punto pp3(0,0);
                  Punto pp4(0,0);
                  *p1 = pp1;
                  *p2 = pp2;
                  *p3 = pp3;
                  *p4 = pp4;      
             }
             //Constructor cuando recibe 4 atributos.
             Rectangulo (Punto pp1, Punto pp2, Punto pp3, Punto pp4){
                  p1 = new (nothrow) Punto;
                  p2 = new (nothrow) Punto;
                  p3 = new (nothrow) Punto;
                  p4 = new (nothrow) Punto;
                  *p1 = pp1;
                  *p2 = pp2;
                  *p3 = pp3;
                  *p4 = pp4;     
             }
             //Destructor.
             ~Rectangulo(){ //Si utilizamos punteros aquí se borran, si no, se escribe un destructor vacío.
                  delete p1;
                  delete p2;
                  delete p3;
                  delete p4;
             };
             //Método mostrar.
             void mostrar(){
                  (*p1).mostrar(); //Llama al método mostrar() de la clase punto.
                  (*p2).mostrar();
                  (*p3).mostrar();
                  (*p4).mostrar();                
             }
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main (){
    Rectangulo r1; //Creamos el objeto r1 de la clase rectángulo utilizando el constructor por defecto, es decir, todos sus atributos a 0.
    Rectangulo r2(2,3); //Creamos el objeto r2 utilizando el constructor 2 donde pone un punto como (2,3) y el resto como 0.
    Punto p1(1,1), p2(2,1), p3(2,3), p4(1,3); //Creamos 4 objetos punto.
    Rectangulo r3(p1,p2,p3,p4); //Creamos el objeto r3 dándole valores a todos sus puntos.
    r1 = r2;
    r1.mostrar();
    cout << endl; //endl es como printf("\n");
    r2.mostrar();
    cout << endl;
    r3.mostrar();
    getchar();
}
