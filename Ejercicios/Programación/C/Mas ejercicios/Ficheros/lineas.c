/* lineas.c

Hacer un programa en c, que lea por teclado
lineas hasta poner que lea la letra f
y las guarde en un fichero de texto.

Despues imprima el contenido en pantalla.

Cada vez q se habra el programa debera crear
el fichero nuevo.
*/

#include <stdio.h>
#include <string.h>

#define  NOMBRE "lineas.txt"
#define  N 80

// ************
void finlinea(char linea[]){
int i;
for (i=0; linea[i]!='\0';i++)
   if (linea[i]=='\n'){
     	   linea[i]='\0';
	   		break;
   }
}

// ************
void leer(){
FILE *f;
char linea[N];
int seguir=0;
	
// Abrimos el fichero para escritura
f=fopen(NOMBRE,"w");
if (f==NULL){
	printf("Error: No se puede abrir para escribir %s",NOMBRE);
}
// Leemos y guardamos palabras
do {
	printf("Introducir palabra (f=fin): ");
	gets(linea); 
	// gets(linea) sin \n = fgets(linea,N+1,stdin) con \n;
	seguir = (strcmp(linea,"f")!=0);
	if (seguir) {
	    fputs(linea,f); // no escribe \0 ni \n
	    fputs("\n",f);
	}
} while (seguir);
fclose(f);
}

// ************
void escribir(){
FILE *f;
char linea[N];
	
// Abrimos el fichero para lectura
f=fopen(NOMBRE,"r");
if (f==NULL){
	printf("Error: No se puede abrir para leer %s",NOMBRE);
}
// Leemos e imprimimos en pantalla
fgets(linea,N,f); // lee la linea, incluido el fin de linea '\n'
while (!feof(f) ){
	finlinea(linea); // quitamos fin de linea
	puts(linea);
	fgets(linea, N ,f);
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
