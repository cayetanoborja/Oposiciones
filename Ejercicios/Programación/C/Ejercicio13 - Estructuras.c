/***********************************************************************************/
/***************************** EJERCICIO C ESTRUCTURAS *****************************/
/***************************** Cayetano Borja Carrillo *****************************/
/***********************************************************************************
Crear un programa en C que contenga los siguientes elementos:
      1) Una estructura que represente puntos formada por sus coordenadas x e y.
      2) Una estructura que represente triángulos utilizando 3 vértices (cada 
        vértice es un elemento de tipo punto).
      3) Una función llamada mostrarCoordenadas que saque  por pantalla las 
        coordenadas de un punto en este formato: (2,3) (x es 2 e y es 3).
      4) Una función llamada cambiarCoordenadas que permita cambiar las
        coordenadas del punto que se envía como parámetro.
      5) Una función llamada distanciaPuntos que devuelva la distancia entre 2
        puntos (que recibe como parámetros de la función).
      6) Una función llamada escribirTriangulo que escriba los vértices del
        triángulo de esta forma, por ejemplo: (3,2),(8,3),(7,5)
      7) Una función llamada perimetroTriangulo que permita escribir el perímetro
        de un triángulo dado. Para solucionarlo, podemos entender que el perímetro
        de un triángulo es la suma de las distancias entre cada vértice.*/

#include <stdio.h>

//Punto 1: Estructura que represente puntos.
typedef struct RepresentarPunto{
	int CoordenadaX, CoordenadaY;
}Punto;

//Punto 2: Estructura que represente triángulos
typedef struct RepresentarTriangulo{
	Punto Vertice1, Vertice2, Vertice3;
}Triangulo;

//Punto 3: Función que muestre por pantalla las coordenadas de un punto.
void mostrarCoordenadas (Punto Punto);

//Punto 4: Función que permite cambiar las coordenadas de un punto.
void cambiarCoordenadas(Punto *Punto);

//Punto 5: Calcular la distancia de los puntos;
float distanciaPuntos(Punto Punto1, Punto Punto2);

//Punto 6: Mostrar los vértices del triángulo
void escribirTriangulo(Triangulo Triangulo);

//Punto 7: Función que calcule el perímetro de un triángulo
float perimetroTriangulo(Triangulo Triangulo);

//EMPEZAMOS EL PROGRAMA.
//En realidad todo esto no hace falta, se hizo para comprobar los datos, lo que se te pide son las funciones.
int main(){
	Punto Punto1, Punto2;
	Triangulo Triangulo;
	int opcion, opcion2, eleccion, hansidoinsertado = 0;
	float distancia, perimetro;
	
	while (opcion != 3){
		printf ("\n Opcion 1: Operar sobre puntos.");
		printf ("\n Opcion 2: Operar sobre triangulos.");
		printf ("\n Opcion 3: Salir del programa.");
		printf ("\n\n Escoge una opcion: ");
		scanf ("%d", &opcion);
		switch (opcion){
			case 1: //Operar sobre puntos.
				//Primero pide las coordenadas de los puntos.
				printf ("\n Introduzca coordenada X del punto 1: ");
				scanf ("%d", &Punto1.CoordenadaX);
				printf ("\n Introduzca coordenada Y del punto 1: ");
				scanf ("%d", &Punto1.CoordenadaY);
				printf ("\n Introduzca coordenada X del punto 2: ");
				scanf ("%d", &Punto2.CoordenadaX);
				printf ("\n Introduzca coordenada Y del punto 2: ");
				scanf ("%d", &Punto2.CoordenadaY);
				
				while (opcion2 != 4){
					printf ("\n Opcion 1: Mostrar coordenadas de un punto.");         
					printf ("\n Opcion 2: Cambiar las coordenadas de un punto."); 
					printf ("\n Opcion 3: Calcular la distancia entre los 2 puntos."); 
					printf ("\n Opcion 4: Volver atras.");
					printf ("\n\n Escoge una opcion: ");
					scanf ("%d", &opcion2);   
					
					switch (opcion2){
					 	case 1: //Mostrar coordenadas de un punto.
							eleccion = 0;
							while ((eleccion != 1) && (eleccion != 2)){
								printf ("\n De que punto quieres ver las coordenadas?");
								printf ("\n\n Elige un punto: ");
								scanf ("%d", &eleccion);
							}
							if (eleccion == 1)
								mostrarCoordenadas (Punto1);            
							else
								mostrarCoordenadas (Punto2);
						break;
						case 2: //Cambiar coordenadas de un punto.
							eleccion = 0;
							while ((eleccion != 1) && (eleccion != 2)){
								printf ("\n De que punto quieres cambiar las coordenadas?");
								printf ("\n\n Elige un punto: ");
								scanf ("%d", &eleccion);
							}
							if (eleccion == 1)
								cambiarCoordenadas (&Punto1);            
							else
								cambiarCoordenadas (&Punto2);
						break;
						case 3:
							distancia = distanciaPuntos(Punto1, Punto2);
							printf ("\n La distancia es: %f\n", distancia);
							getchar(); getchar();
						break;
						case 4: //Vuelve atrás.
						break;
						default:
							printf ("\n\n Opcion invalida, intentalo de nuevo.\n");
							getchar(); getchar();
						break;
					}    
				}                   
			break;
			case 2: //Operar sobre triángulos.
				//Primero pide las coordenadas de los triangulos.
				printf ("\n Introduzca coordenada X del vertice 1: ");
				scanf ("%d", &Triangulo.Vertice1.CoordenadaX);
				printf ("\n Introduzca coordenada Y del vertice 1: ");
				scanf ("%d", &Triangulo.Vertice1.CoordenadaY);
				printf ("\n Introduzca coordenada X del vertice 2: ");
				scanf ("%d", &Triangulo.Vertice2.CoordenadaX);
				printf ("\n Introduzca coordenada Y del vertice 2: ");
				scanf ("%d", &Triangulo.Vertice2.CoordenadaY);
				printf ("\n Introduzca coordenada X del vertice 3: ");
				scanf ("%d", &Triangulo.Vertice3.CoordenadaX);
				printf ("\n Introduzca coordenada Y del vertice 3: ");
				scanf ("%d", &Triangulo.Vertice3.CoordenadaY);
				
				while (opcion2 != 3){
					printf ("\n Opcion 1: Mostrar los vertices del triangulo.");         
					printf ("\n Opcion 2: Calcular el perimetro del triangulo.");  
					printf ("\n Opcion 3: Volver atras.");
					printf ("\n\n Escoge una opcion: ");
					scanf ("%d", &opcion2);   
					
					switch (opcion2){
						case 1: //Mostrar los vertices del triangulo.
							escribirTriangulo(Triangulo);                             
						break;
						case 2: //Calcular el perimetro del triangulo (es la suma de todos sus lados).
							perimetro = perimetroTriangulo(Triangulo);
							printf ("\n El perimetro del triangulo es: %f", perimetro);
							getchar(); getchar();
						break;
						case 3: //Vuelve atrás.
						break;
						default:
							printf ("\n\n Opcion invalida, intentalo de nuevo.\n");
							getchar(); getchar();
						break;
					}    
				}    
			break;
			case 3: //Sale del programa.
			break;
			default: //Cualquier otra opcion.
				printf ("\n\n Opcion invalida, intentalo de nuevo.\n");
				getchar();
			break;
		}
	}        
}

//LAS FUNCIONES.
//Función que muestre por pantalla las coordenadas de un punto.
void mostrarCoordenadas (Punto Punto){
	printf("\n Las coordenadas del punto son: (%d,%d)", Punto.CoordenadaX, Punto.CoordenadaY); 
	getchar(); getchar();   
}

//Función que permite cambiar las coordenadas de un punto.
void cambiarCoordenadas (Punto *Punto){
	printf ("\n Introduzca la nueva coordenada X del punto: ");
	scanf ("%d", &(*Punto).CoordenadaX);
	printf ("\n Introduzca la nueva coordenada Y del punto: ");
	scanf ("%d", &(*Punto).CoordenadaY);
}

//Función que devuelve la distancia entre 2 puntos.
float distanciaPuntos(Punto Punto1, Punto Punto2){
	float DistanciaTotal, DistanciaX, DistanciaY;
	DistanciaX = abs (Punto1.CoordenadaX - Punto2.CoordenadaX);
	DistanciaY = abs (Punto2.CoordenadaY - Punto2.CoordenadaY);
	DistanciaTotal = sqrt(pow(DistanciaX,2) + (DistanciaY, 2)); //Aplicamos el teorema de pitágoras.
	return (DistanciaTotal);
}

//Función que muestre los vértices del triángulo.
void escribirTriangulo(Triangulo Triangulo){
	printf("\n Las coordenadas del vertice 1 son: (%d,%d)", Triangulo.Vertice1.CoordenadaX, Triangulo.Vertice1.CoordenadaY);
	printf("\n Las coordenadas del vertice 2 son: (%d,%d)", Triangulo.Vertice2.CoordenadaX, Triangulo.Vertice2.CoordenadaY); 
	printf("\n Las coordenadas del vertice 3 son: (%d,%d)", Triangulo.Vertice3.CoordenadaX, Triangulo.Vertice3.CoordenadaY);  
	getchar(); getchar();            
}

//Función que calcule el perímetro de un triángulo
float perimetroTriangulo(Triangulo Triangulo){
	float perimetro;
	perimetro = distanciaPuntos(Triangulo.Vertice1, Triangulo.Vertice2) +
		distanciaPuntos(Triangulo.Vertice1, Triangulo.Vertice3) +
		distanciaPuntos(Triangulo.Vertice2, Triangulo.Vertice3);
	return (perimetro);
}
