/***********************************************************************************/
/***************************** EJERCICIO HERENCIA 3 C++ ****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: Si los objetos se declaran dinámicamente, se puede utilizar la ligadura
tardía (también llamado enlace dinámico) que consiste en declarar un objeto de clase
padre y, más tarde, enlazarlo con el tipo que sea. Ejemplo:
    
Implementar el ejercicio anterior pero en vez de crear todos los objetos seguidos, 
preguntar qué tipo de cuenta se quiere crear y consultar sólo esa.    
             
/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
using namespace std;

//CLASE CUENTA.
class Cuenta{
      //Atributos.
      protected:
              string Titular;
              double Saldo;
      //Métodos.
      public:
             //Constructor por defecto.
             Cuenta (){}
             //Constructor que recibe 2 atributos;
             Cuenta (const string &Titular, double Saldo){
                    this->Titular = Titular;
                    this->Saldo = Saldo;
             }
             //Método de devolución de Titular.
             string getTitular(){
                    return Titular;
             }
             //Método de devolución de Saldo.
             double getSaldo(){
                    return Saldo;
             }
             //Método de modificación de Titular.
             void setTitular (const string &Titular){
                    this->Titular = Titular;
             }
             //Método de modificación de Saldo. 
             void setSaldo (double Saldo){
                    this->Saldo = Saldo;  
             }
             //Método Reintegro. Se pone virtual por si se sobreescribe en el hijo para que se ejecute la del hijo antes que esta.
             virtual void Reintegro (double Cantidad){
                  if (Saldo == 0){
                            Saldo -= Cantidad;
                  }
                  else{
                       cout << endl << "No se puede sacar dinero de la cuenta porque no tiene suficiente." << endl;
                  }
             }
             //Método Ingreso.
             virtual void Ingreso (double Cantidad){
                  Saldo += Cantidad;
             }
             //Método toString.
             virtual string toString (){
                    string Cadena;
                    Cadena += "Titular: ";
                    Cadena += Titular;
                    Cadena += ", Saldo: ";
       //             Cadena += Saldo;
                    return Cadena;   
             } 
};

//CLASE CUENTA DE CRÉDITO HIJA DE LA CLASE CUENTA.
class CuentaCredito : public Cuenta{ //Hereda de la clase Cuenta.
      public:
             //Se ha de definir un constructor.
             CuentaCredito (const string &Titular, double Saldo) : Cuenta (Titular, Saldo){}
             //Utilizamos el polimorfismo en el método Reintegro.
             void Reintegro (double Cantidad){
                  Saldo -= Cantidad;
                  if (Saldo < 0){
                            Saldo -= Cantidad * 0.01;
                  }
             } 
};

//CLASE CUENTA DE NÓMINA.
class CuentaNomina : public Cuenta{
      private:
             double Nomina;
      public:
             //Constructor
             CuentaNomina (const string &Titular, double Saldo, double Nomina) : Cuenta(Titular, Saldo){
                           this->Nomina = Nomina; //Cuenta inicializa Titular y Saldo pero no Nomina, los atributos propios se ponen como siempre.
             }
             //Método Registro.             
             void Reintegro (double Cantidad){
                 if ((Saldo - Cantidad) >= (0 - Nomina)){
                            Saldo -= Cantidad;           
                 }
                 else{
                      cout << "No se puede hacer reintegro, se quedaria un saldo negativo mayor a la nomina." << endl << endl;
                      
                 }
             }
};

//CLASE CUENTA DE AHORRO.
class CuentaAhorro : public Cuenta{
      public:
             //Constructor.
             CuentaAhorro (const string &Titular, double Saldo) : Cuenta (Titular, Saldo){}
             //Método Ingreso.             
             void Ingreso (double Cantidad){
                  Saldo += Cantidad * 1.01;
             }
};

//CLASE CUENTA JOVEN.      
class CuentaJoven : public Cuenta{
      private:
              int Edad;
      public:
             //Constructor
             CuentaJoven (const string &Titular, double Saldo, int Edad) : Cuenta (Titular, Saldo){
                         this->Edad = Edad;   
             }  
             //Método Reintegro.
             void Reintegro (double Cantidad){
                  if (Edad <= 25){
                           if (Saldo == 0){
                                     Saldo -= Cantidad;
                           }
                           else{
                                     cout << endl << "No se puede sacar dinero de la cuenta porque no tiene suficiente." << endl;
                           }
                  }
                  else{
                       cout << endl << "No se pueden realizar operaciones, la edad es mayor a 25." << endl;
                  }
             }
             //Método Ingreso.
             void Ingreso (double Cantidad){
                  if (Edad <= 25){                  
                           Saldo += Cantidad;
                  }
                  else{
                       cout << endl << "No se pueden realizar operaciones, la edad es mayor a 25." << endl;
                  }                  
             }
};      


/***********************************************************************************/
/**************************** INICIO DEL PROGRAMA **********************************/
/***********************************************************************************/
int main(){
    Cuenta *Cuenta; //Creamos el objeto pero no lo inicializamos.
    int opcion;
    while ((opcion < 1) || (opcion > 4)){
          cout << "Opcion 1: Consultar Cuenta de Credito." << endl;
          cout << "Opcion 2: Consultar Cuenta de Nomina." << endl;
          cout << "Opcion 3: Consultar Cuenta de Ahorro." << endl;
          cout << "Opcion 4: Consultar Cuenta Joven." << endl << endl;
          cout << "Eliga una opcion: ";
          cin >> opcion;
          switch (opcion){
                 case 1:
                      Cuenta = new CuentaCredito("Juan",100); //Lo inicializamos como CuentaCredito.
                 break;
                 case 2:
                      Cuenta = new CuentaNomina("Juan",100, 100);
                 break;
                 case 3:
                      Cuenta = new CuentaAhorro("Juan",100);
                 break;
                 case 4:
                      Cuenta = new CuentaJoven("Juan",100, 25);
                 break;
                 default:
                         cout << endl << "Opcion invalida, intentalo de nuevo." << endl;
                         getchar();
                         getchar();
                 break;
           }  
    }
    
    Cuenta->Ingreso (50); //Sea del tipo que sea el objeto ejecuta el método.
    Cuenta->Reintegro (200);
    cout << endl << "Saldo: " << Cuenta->getSaldo() << endl;   
    delete Cuenta;         
    getchar();
    getchar();
    
}
