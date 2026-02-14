/* palabras.c
Hacer un programa en c, que lea por teclado
palabras hasta poner que lea la letra f
y las guarde en un fichero de texto.
Despues imprima el contenido en pantalla.
Cada vez q se habra el progama debera crear
el fichero nuevo.
*/

#include <stdio.h>
#include <string.h>

#define  NOMBRE "palabra.txt"
#define  N 30

// ************
void leer(){
FILE *f;
char palabra[N];
int salir=0;
	
// Abrimos el fichero para escritura
f=fopen(NOMBRE,"w");
if (f==NULL){
	printf("Error: No se puede abrir para escribir %s",NOMBRE);
}
// Leemos y guardamos palabras
do {
	printf("Introducir palabra (f=fin): ");
	gets(palabra);
	salir= ( strcmp(palabra,"f")==0 );
	if (!salir)
		fprintf(f,"%s\n",palabra);
} while ( !salir );
fclose(f);
}

// ************
void escribir(){
FILE *f;
char palabra[N];
	
// Abrimos el fichero para lectura
f=fopen(NOMBRE,"r");
if (f==NULL){
	printf("Error: No se puede abrir para leer %s",NOMBRE);
}
// Leemos e imprimimos en pantalla
fscanf(f,"%s",palabra);
while (!feof(f) ){
	printf("%s\n", palabra);
	fscanf(f,"%s",palabra);
}
fclose(f);
}
	
// ********************
main(){
leer();
escribir();
}

/* Ejecucion
Introducir palabra (f=fin): aaa
Introducir palabra (f=fin): bbb
Introducir palabra (f=fin): ccc
Introducir palabra (f=fin): f
aaa
bbb
ccc
*/
