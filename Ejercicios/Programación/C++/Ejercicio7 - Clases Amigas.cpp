/***********************************************************************************/
/*************************** EJERCICIO CLASES AMIGAS C++ ***************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: Si una clase es amiga de otra, puede acceder a la parte privada de ésta.
Que una clase sea amiga de otra, no tiene por qué ser la otra amiga de la primera.

Realizar la implementación de una clase Coche con atributos NumRuedas, Caballos,
Matricula y Color y otra clase Moto con atributos CentímetrosCúbicos, Matricula y
Color. Hacer que la clase Coche sea amiga de Moto, de tal forma que cuando se utilice
el método de modificación de color de la moto, ponga el mismo color que tiene el coche.
   
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/   
#include <iostream>

using namespace std;      

//DEFINIMOS LA CLASE COCHE.
class Coche{
      //DEFINIMOS LOS ATRIBUTOS.
      private:
              friend class Moto; //Privado excepto para Moto.
              int NumRuedas;
              int Caballos;
              string Matricula;
              string Color;
      //DEFINIMOS LOS MÉTODOS.
      public:
             //Constructor por defecto.
             Coche (){}
             //Constructor que recibe 4 parametros.
             Coche (int NumRuedas, int Caballos, const string &Matricula, const string &Color){
                   this->NumRuedas = NumRuedas;
                   this->Caballos = Caballos;
                   this->Matricula = Matricula;
                   this->Color = Color;  
             }
             //Destructor.
             ~Coche(){}
             //Método de devolución Color.
             string getColor(){
                   return Color;
             };
};

//DEFINIMOS LA CLASE MOTO.
class Moto{
      //DEFINIMOS LOS ATRIBUTOS.
      private:
              int CentimetrosCubicos;
              string Matricula;
              string Color;
      //DEFINIMOS LOS MÉTODOS.
      public:
             //Constructor por defecto.
             Moto (){}
             //Constructor que recibe 3 parametros.
             Moto (int CentimetrosCubicos, const string &Matricula, const string &Color){
                   this->CentimetrosCubicos = CentimetrosCubicos;
                   this->Matricula = Matricula;
                   this->Color = Color;  
             }
             //Destructor.
             ~Moto(){}
             //Método de devolución Color.
             string getColor(){
                    return Color;
             }
             //Método de modificación de Color
             void setColor(Coche Coche1){ //Como es amiga devolvera el color del coche.
                   Color = Coche1.Color; //No hace falta llamar al método getColor(), porque para la clase Moto, los atributos del coche son públicos, entonces puede acceder directamente.
             }
};

/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main (){
    Coche Coche1(4,120,"8855","rojo");
    Moto Moto1(90,"7543","amarillo");
    cout << Moto1.getColor() << endl;
    Moto1.setColor(Coche1);
    cout << Moto1.getColor() << endl;
    getchar();
}
