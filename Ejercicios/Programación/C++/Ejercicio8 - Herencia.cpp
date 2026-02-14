/***********************************************************************************/
/***************************** EJERCICIO HERENCIA 1 C++ ****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: Cuando una clase es hija de otra clase, hereda todos los atributos y
métodos de la padre, es decir, es lo mismo que copiar todo lo de la clase padre
y pegarlo dentro de la clase hija. A parte, la clase hija puede tener atributos y 
métodos propios. Se llama Polimorfismo cuando una clase padre posee un método y la 
clase hija lo sobreescribe cambiando la forma de ejecución, de forma que si se accede 
a un método que está definido en la clase hija y padre, se ejecutará la de la hija.           
             
Dentro de un sistema bancario que ya está funcionando disponemos de una clase
CUENTA, los datos que guarda dicha clase son los siguientes:
        - string Titular: Nombre del dueño de la cuenta.
        - double Saldo: Dinero disponible en la cuenta.
Además una cuenta tiene los siguientes métodos:
       - Los constructores correspondientes.
       - Los métodos de modificación y de devolución.
       - Un método reintegro, que recibe una cantidad y lo saca de la cuenta (resta del saldo).
       - Un método ingreso, que recibe una cantidad y lo mete en la cuenta (suma al saldo).
       - Un método toString, para poder escribir los datos de la cuenta en pantalla.
La nueva política del banco exige que tengamos otros tipos de cuentas con
características diferentes. En particular debemos admitir los siguientes tipos:
       - Cuenta de crédito: Permite obtener reintegros hasta un saldo negativo fijo 
         para cada cuenta y, si el saldo es negativo el banco le cobra un 1% más.
       - Cuenta de nómina: Permite obtener reintegros hasta un saldo negativo igual
         al importe mensual de la nómina que el cliente tiene domiciliada en dicha cuenta.
       - Cuenta de ahorro: No admite saldo negativo. Cada vez que se ingresa una
         cantidad se suma el 0,1%.
       - Cuenta joven: Exige que el cliente sea menor de 25 años.
Crear un programa principal donde definas una cuenta de cada clase, con un saldo
inicial de 100€, realiza una operación de ingreso de 50€ y un reintegro de 200€,
muestra los saldos de cada cuenta.

/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/  
#include <iostream>
using namespace std;

//CLASE CUENTA.
class Cuenta{
      //Atributos.
      protected: //Protegido, quiere decir que es privado para todas las clases excepto para sus hijos que es público.
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
             //Destructor.
             ~Cuenta(){};
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
             //Método Reintegro.
             void Reintegro (double Cantidad){
                  if (Saldo == 0){
                            Saldo -= Cantidad;
                  }
                  else{
                       cout << endl << "No se puede sacar dinero de la cuenta porque no tiene suficiente." << endl << endl;
                  }
             }
             //Método Ingreso.
             void Ingreso (double Cantidad){
                  Saldo += Cantidad;
             }
             //Método toString.
             string toString (){
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
             CuentaCredito (const string &Titular, double Saldo)  : Cuenta (Titular,Saldo){}
             
             /* Se podría haber definido así:
                   CuentaCredito (const string &Titular, double Saldo){
                           this->Titular = Titular;
                           this->Saldo = Saldo;
                   }
                   Pero cuando se hereda es preferible hacerlo como se ha hecho, es decir, llamar al constructor del padre*/
                   
             //Utilizamos el polimorfismo en el método Reintegro.
             void Reintegro (double Cantidad){
                  Saldo -= Cantidad; //Se puede hacer porque los atributos de la clase padre son protegidos, si fueran privados se debería usar getSaldo.
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
    CuentaCredito Credito ("Juan",100);
    CuentaNomina Nomina ("Juan",100, 100);
    CuentaAhorro Ahorro ("Juan",100);
    CuentaJoven Joven ("Juan",100, 25);    
    cout << "CUENTA DE CREDITO:" << endl << endl;
    Credito.Ingreso (50);
    Credito.Reintegro (200);
    cout << "Saldo: " << Credito.getSaldo() << endl;
    cout << endl << "CUENTA DE NOMINA:" << endl << endl;    
    Nomina.Ingreso (50);
    Nomina.Reintegro (200);    
    cout << "Saldo: " << Nomina.getSaldo() << endl; 
    cout << endl << "CUENTA DE AHORRO:" << endl;        
    Ahorro.Ingreso (50);
    Ahorro.Reintegro (200);
    cout << "Saldo: " << Ahorro.getSaldo() << endl; 
    cout << endl << "CUENTA JOVEN:" << endl;        
    Joven.Ingreso (50);
    Joven.Reintegro (200);
    cout << endl << "Saldo: " << Joven.getSaldo() << endl;                 
    getchar();
    getchar();
    
}
