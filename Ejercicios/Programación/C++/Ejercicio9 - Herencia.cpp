/***********************************************************************************/
/***************************** EJERCICIO HERENCIA 2 C++ ****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
EXPLICACIÓN: En los ejercicios anteriores, los objetos se han creado estáticamente pero
lo más común es hacerlo dinámicamente (con punteros). Si se crean dinámicamente, se
hereda y se sobreescribe un método, no se produce polimorfismo, es decir, que se
ejecutará la del padre aunque esté sobreescrita en la hija. Para crear polimorfismo en
objetos dinámicos, se tienen que crear los métodos del padre que están definidos en la
hija como virtuales, de forma que si es virtual mirará primero si lo tiene definido
la hija, ejecutándose si lo tiene en ella. Ejemplo:
             
Implementar el ejercicio anterior haciendo uso de objetos dinámicos.  
             
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
    Cuenta *Credito = new CuentaCredito("Juan",100); //Se crea el objeto como puntero
    //Tambien se puede crear así: CuentaCredito *Credito = new CuentaCredito("Juan",100);, pero en el ejercicio siguiente se verá porque a veces es aconsejable declararlo de la clase padre.
    Cuenta *Nomina = new CuentaNomina("Juan",100, 100);
    Cuenta *Ahorro = new CuentaAhorro("Juan",100);
    Cuenta *Joven = new CuentaJoven ("Juan",100, 25);    
    cout << "CUENTA DE CREDITO:" << endl << endl;
    Credito->Ingreso (50); //No se pone Credito.Ingreso sino con la flecha porque son punteros.
    Credito->Reintegro (200);
    cout << "Saldo: " << Credito->getSaldo() << endl;
    cout << endl << "CUENTA DE NOMINA:" << endl << endl;    
    Nomina->Ingreso (50);
    Nomina->Reintegro (200);    
    cout << "Saldo: " << Nomina->getSaldo() << endl; 
    cout << endl << "CUENTA DE AHORRO:" << endl;        
    Ahorro->Ingreso (50);
    Ahorro->Reintegro (200);
    cout << endl << "Saldo: " << Ahorro->getSaldo() << endl; 
    cout << endl << "CUENTA JOVEN:" << endl;        
    Joven->Ingreso (50);
    Joven->Reintegro (200);
    cout << endl << "Saldo: " << Joven->getSaldo() << endl;                 
    getchar();
    getchar();
    delete Credito; //Los punteros han de borrarse.
    delete Nomina;
    delete Ahorro;
    delete Joven;         
    getchar();
    getchar();
    
}
