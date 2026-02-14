/***********************************************************************************/
/*************************** EJERCICIO COMPOSICIÓN 4 C++ ***************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Queremos crear un programa para gestionar un videoclub, para ello vamos a hacer
una clase que represente una película. De las películas, vamos a guardar un
código, un nombre, un genero y la cantidad de discos que tenemos. El código
debe empezar con la palabra "DVD". La cantidad debe ser mayor que 0. Vamos a
crear los siguientes métodos:
      - Constructores.
      - Métodos de devolución y modificación.
      - Métodos toString que devuelve una cadena con información de la película.
      - Indicar_venta: Decrementa la cantidad de discos. Si la cantidad es 0
        no se puede decrementar y se debe indicar un mensaje de que no se puede
        vender.
Después, crea la clase videoclub, en la que vamos a tener 2 atributos: el nombre
del videoclub y un conjunto de películas. Vamos a tener los siguientes métodos:
      - Un constructor.
      - Añadir_película: Lee los datos de una película y lo introduce en el vector.
      - Borra_película: Pide el código de una película y si lo encuentra lo borra.
      - Listar_películas: Lista todas las películas.
      - Buscar_películas: Me pregunta por que atributo quiero buscar (por código,
        por nombre, por género o por cantidad).
      - Vender: Pide el código de una película y si está en el vector se
        decrementa la cantidad de discos. 
      - Mostrar_películas_que_faltan: Muestra las películas cuya cantidad es 0.
Crear un programa principal que muestre un menú que permita gestionar el videoclub.*/

/***********************************************************************************/
/******************************** LIBRERÍAS Y CLASES *******************************/
/***********************************************************************************/
#include <iostream>
#define NumPeliculas 10
using namespace std;

//CLASE PELÍCULA.
class Pelicula{
      //Atributos.
      private:
              string Codigo;
              string Nombre;
              string Genero;
              int Cantidad;
      //Métodos.        
      public:
             //Constructor por defecto.
             Pelicula (){};
             //Constructor que recibe 4 parámetros.
             Pelicula (const string &Codigo, const string &Nombre, const string &Genero, int Cantidad){
                      this->Codigo = Codigo;
                      this->Nombre = Nombre;
                      this->Genero = Genero;
                      this->Cantidad = Cantidad;
             };
             //Destructor.
             ~Pelicula (){};
             //METODOS DE DEVOLUCIÓN.
             //Método para acceder a código
             string getCodigo(){
                    return Codigo;
             }
             //Método para acceder a nombre;
             string getNombre(){
                    return Nombre;
             }
             //Método para acceder a genero;
             string getGenero(){
                    return Genero;
             }
             //Método para acceder a cantidad;
             int getCantidad(){
                    return Cantidad;
             }           
             //METODOS DE MODIFICACIÓN.
             //Método para escribir en código
             void setCodigo(const string &Codigo){
                    this->Codigo = Codigo;
             }
             //Método para acceder a nombre;
             void setNombre(const string &Nombre){
                    this->Nombre = Nombre;
             }
             //Método para acceder a genero;
             void setGenero(const string &Genero){
                    this->Genero = Genero;
             }
             //Método para acceder a cantidad;
             void setCantidad(int Cantidad){
                    this->Cantidad = Cantidad;
             }             
             
             //MÉTODO TOSTRING
             string toString (){
                 //   string CantidadCaracter = itoa (Cantidad_.c_str());
                    string Cadena = Codigo;
                    Cadena += ": ";
                    Cadena += Nombre;
                    Cadena += ", ";
                    Cadena += Genero;
                    Cadena += ", ";
                   // Cadena += Cantidad_; //Lo pongo entre comentarios porque me pasa valores raros
                    return Cadena;   
             }  
             //MÉTODO INDICAR_VENTA.  
             void Indicar_venta(){
                  if (Cantidad > 0){
                         Cantidad -= 1;
                         cout << endl << "Venta realizada.";                    
                  }
                  else{
                       cout << endl << "No se puede vender ya que no hay existencias.";    
                  } 
             }       
};

//CLASE VIDEOCLUB.
class Videoclub{
      private:
              string Nombre;
              Pelicula Peliculas[NumPeliculas];            
      public:
             //Constructor.
             Videoclub(const string &Nom){
                   Nombre = Nom; //No se llama nombre, no hace falta this.
             };
             //Destructor.
             ~Videoclub(){};
             //Método para acceder al nombre.
             string getNombre(){
                    return Nombre;
             }
             //Método Añadir_película.
             void Anadir_pelicula (const string &Codigo, const string &Nombre, const string &Genero, int Cantidad){
                  int i = 0;
                  Pelicula PeliculaAIngresar(Codigo,Nombre,Genero,Cantidad);
                  while (Peliculas[i].getCodigo() != ("")){ //Buscamos un hueco libre y nos posicionamos.
                        i++;
                  }
                  Peliculas[i] = PeliculaAIngresar;                       
             }
             //Método Borrar pelicula.
             void Borrar_pelicula(){
                  string Codigo;
                  int i = 0, j = 0, eliminado = 0, Repite = 0;
                  
                  if (Peliculas[0].getCodigo() == ("")){
                          cout << endl << "No hay peliculas ingresadas.";                                       
                  }
                  else
                  {
                      while (Repite == 0){
                             cout << endl << "Introduce el codigo de pelicula: ";
                             cin >> Codigo;
                             if ((Codigo[0] == 'D') && (Codigo[1] == 'V') && (Codigo[2] == 'D')){
                                 Repite = 1;                     
                             }
                             else{
                                 cout << endl << "El codigo debe empezar por 'DVD', intentalo de nuevo.";
                                 getchar();
                                 getchar();
                             }                        
                       }
                       while (Peliculas[i].getCodigo() != ("")){ 
                                if (Peliculas[i].getCodigo() == Codigo){ 
                                        j = i;
                                        //Movemos todos los posteriores una posición atrás sobreescribiendo el contacto a borrar.
                                        while (Peliculas[j].getCodigo() != ("")){
                                              Peliculas[j].setCodigo(Peliculas[j+1].getCodigo());
                                              Peliculas[j].setNombre(Peliculas[j+1].getNombre());
                                              Peliculas[j].setGenero(Peliculas[j+1].getGenero());
                                              Peliculas[j].setCantidad(Peliculas[j+1].getCantidad());
                                              j++;  
                                        }
                                        eliminado += 1;
                                        i--;
                                }
                                i++; 
                       }
                       if (eliminado > 0){
                                cout << endl << "Se han eliminado " << eliminado << " peliculas.";        
                       }
                       else{
                                cout << endl << "No existen peliculas con ese codigo.";
                       }
                  }
                  getchar();
                  getchar();
                  cout << endl; 
             }
             //Método Listar_películas.
             void Listar_peliculas (){
                  int i = 0;
                  if (Peliculas[0].getCodigo() == ("")){
                          cout << endl << "No hay peliculas ingresadas.";                                     
                  }
                  else
                  {
                      while (Peliculas[i].getCodigo() != ("")){
                            cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                            i++;
                      }      
                  }
                  getchar();
                  getchar(); 
                  cout << endl; 
             }
             //Método Buscar_Peliculas.
             void Buscar_peliculas(){
                  int opcion2 = 0, i = 0, Cantidad, Encontrado, Repite;
                  string Cadena;
                  if (Peliculas[0].getCodigo() == ("")){
                          cout << endl << "No hay peliculas ingresadas."; 
                          getchar();
                          getchar();
                          cout << endl;                                      
                  }
                  else{
                       system ("cls");
                       while (opcion2 != 5){
                             cout << "VIDEOCLUB: "<< getNombre() << endl << endl;
                             cout << "Opcion 1: Buscar por Codigo." << endl;
                             cout << "Opcion 2: Buscar por Nombre." << endl;
                             cout << "Opcion 3: Buscar por Genero." << endl;
                             cout << "Opcion 4: Buscar por Cantidad." << endl;
                             cout << "Opcion 5: Volver atras." << endl << endl;
                             cout << "Elige una opcion: ";
                             cin >> opcion2;
                             switch (opcion2){
                                    //Opción 1: Buscar por Código.
                                    case 1:
                                         Encontrado = 0;
                                         i = 0;
                                         Repite = 0;
                                         while (Repite == 0){
                                               cout << endl << "Introduce el codigo de pelicula: ";
                                               cin >> Cadena;
                                               if ((Cadena[0] == 'D') && (Cadena[1] == 'V') && (Cadena[2] == 'D')){
                                                       Repite = 1;                     
                                               }
                                               else{
                                                       cout << endl << "El codigo debe empezar por 'DVD', intentalo de nuevo.";
                                                       getchar();
                                                       getchar();
                                               }                        
                                         }
                                         while (Peliculas[i].getCodigo() != ("")){
                                               if (Peliculas[i].getCodigo() == Cadena){
                                                       cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                                                       Encontrado = 1;                       
                                               }
                                               i++;
                                         }
                                         if (Encontrado == 0){
                                                        cout << endl << "No se han encontrado peliculas con ese nombre.";            
                                         }
                                         getchar();
                                         getchar();
                                         cout << endl;
                                    break;
                                    //Opción 2: Buscar por Nombre.
                                    case 2:
                                         Encontrado = 0;
                                         i = 0;
                                         cout << endl << "Introduce un nombre: ";
                                         cin >> Cadena;
                                         while (Peliculas[i].getCodigo() != ("")){
                                               if (Peliculas[i].getNombre() == Cadena){
                                                       cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                                                       Encontrado = 1;                       
                                               }
                                               i++;
                                         }
                                         if (Encontrado == 0){
                                                        cout << endl << "No se han encontrado peliculas con ese nombre.";            
                                         }
                                         getchar();
                                         getchar();
                                         cout << endl;
                                    break;
                                    //Opción 3: Buscar por Genero.
                                    case 3:
                                         Encontrado = 0;
                                         i = 0;
                                         cout << endl << "Introduce el genero: ";
                                         cin >> Cadena;
                                         while (Peliculas[i].getCodigo() != ("")){
                                               if (Peliculas[i].getGenero() == Cadena){
                                                       cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                                                       Encontrado = 1;                       
                                               }
                                               i++;
                                         }
                                         if (Encontrado == 0){
                                                        cout << endl << "No se han encontrado peliculas de ese genero.";            
                                         }
                                         getchar();
                                         getchar();
                                         cout << endl;
                                    break;
                                    //Opción 4: Buscar por Cantidad.
                                    case 4:
                                         Cantidad = -1;
                                         Encontrado = 0;
                                         i = 0;
                                         while (Cantidad < 0){
                                               cout << endl << "Introduce la cantidad de peliculas: ";
                                               cin >> Cantidad;
                                               if (Cantidad < 0){
                                                            cout << endl << "La cantidad debe de ser superior o igual a 0, intentalo de nuevo.";
                                                            getchar();
                                                            getchar();
                                                            cout << endl;
                                               }
                                         }
                                         while (Peliculas[i].getCodigo() != ("")){
                                               if (Peliculas[i].getCantidad() == Cantidad){
                                                       cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                                                       Encontrado = 1;                       
                                               }
                                               i++;
                                         }
                                         if (Encontrado == 0){
                                                        cout << endl << "No se han encontrado peliculas con esa cantidad.";            
                                         }
                                         getchar();
                                         getchar();
                                         cout << endl;                                  
                                    break;
                                    //Opción 5: Volver atrás.
                                    case 5:
                                         system ("cls");
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
             }                        
                              
             //Método Vender.
             void Vender(){
                  string Codigo;
                  int i = 0, encontrado = 0, Repite = 0;
                  
                  if (Peliculas[0].getCodigo() == ("")){
                          cout << endl << "No hay peliculas ingresadas.";                                       
                  }
                  else{
                       while (Repite == 0){
                             cout << endl << "Introduce el codigo de pelicula: ";
                             cin >> Codigo;
                             if ((Codigo[0] == 'D') && (Codigo[1] == 'V') && (Codigo[2] == 'D')){
                                 Repite = 1;                     
                             }
                             else{
                                 cout << endl << "El codigo debe empezar por 'DVD', intentalo de nuevo.";
                                 getchar();
                                 getchar();
                             }                        
                       }
                          while ((Peliculas[i].getCodigo() != ("")) && (encontrado == 0)){
                                if (Peliculas[i].getCodigo() == Codigo){
                                      Peliculas[i].Indicar_venta();                       
                                      encontrado = 1;                       
                                }
                                i++;
                          }
                          if (encontrado == 0){
                                cout << endl << "No se han encontrado peliculas con ese codigo.";            
                          } 
                  }
                  getchar();
                  getchar(); 
                  cout << endl;                  
             }
             //Método Mostrar_peliculas_que_faltan
             void Mostrar_peliculas_que_faltan(){
                  int i = 0, existen = 0;
                  
                  if (Peliculas[0].getCodigo() == ("")){
                          cout << endl << "No hay peliculas ingresadas.";                                       
                  }
                  else{
                          while (Peliculas[i].getCodigo() != ("")){
                               if (Peliculas[i].getCantidad() == 0){
                                      cout << endl << Peliculas[i].toString() << Peliculas[i].getCantidad();
                                      existen = 1;                       
                                }
                                i++;
                          }
                          if (existen == 0){
                                cout << endl << "No se han encontrado peliculas cuya cantidad es 0.";            
                          } 
                  }
                  getchar();
                  getchar(); 
                  cout << endl;                 
             }   
};

int main(){
    Videoclub Videoclub("El Planeta de los videos");
    int opcion, Cantidad = -1, Repite = 0;
    string Codigo, Nombre, Genero;
    
    while (opcion != 7){
          cout << "VIDEOCLUB: "<< Videoclub.getNombre() << endl << endl;
          cout << "Opcion 1: Introducir una pelicula." << endl;
          cout << "Opcion 2: Borrar una pelicula." << endl;
          cout << "Opcion 3: Listar las peliculas." << endl;
          cout << "Opcion 4: Buscar una pelicula." << endl;
          cout << "Opcion 5: Vender una pelicula." << endl;
          cout << "Opcion 6: Mostrar peliculas que faltan." << endl;
          cout << "Opcion 7: Salir del programa." << endl << endl;
          cout << "Escoge una opcion: ";
          cin >> opcion;
          switch (opcion){
                 //Opción 1: Introducir una pelicula.
                 case 1:
                      Repite = 0;
                      Cantidad = 0;
                      while (Repite == 0){
                            cout << endl << "Introduce el codigo de pelicula: ";
                            cin >> Codigo;
                            if ((Codigo[0] == 'D') && (Codigo[1] == 'V') && (Codigo[2] == 'D')){
                                 Repite = 1;                     
                            }
                            else{
                                 cout << endl << "El codigo debe empezar por 'DVD', intentalo de nuevo.";
                                 getchar();
                                 getchar();
                            }                        
                      }
                      cout << endl << "Introduce el nombre de la pelicula: ";
                      cin >> Nombre;
                      cout << endl << "Introduce el genero de la pelicula: ";
                      cin >> Genero;  
                      while (Cantidad <= 0){
                            cout << endl << "Introduce la cantidad de peliculas: ";
                            cin >> Cantidad;
                            if (Cantidad <= 0){
                                  cout << endl << "La cantidad debe de ser superior a 0, intentalo de nuevo.";
                                  getchar();
                                  getchar();
                            }
                      }
                      Videoclub.Anadir_pelicula(Codigo, Nombre, Genero, Cantidad);
                      cout << endl << "Pelicula insertada." << endl;
                      getchar();
                      getchar();                                           
                 break;
                 //Opción 2: Borra Pelicula
                 case 2:
                      Videoclub.Borrar_pelicula();
                 break;
                 //Opción 3: Listar películas
                 case 3:
                      Videoclub.Listar_peliculas();
                 break;
                 //Opción 4: Buscar Peliculas
                 case 4:
                      Videoclub.Buscar_peliculas();
                 break;
                 //Opción 5: Vender peliculas
                 case 5:
                      Videoclub.Vender();
                 break;
                 //Opción 6: Mostrar las peliculas cuya cantidad es 0.
                 case 6:
                      Videoclub.Mostrar_peliculas_que_faltan();
                 break;
                 //Caso 7: Salir del programa.                 
                 case 7:
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
