/* mayusculas.c
Hacer un programa en c, que lea por teclado
el nombre del fichero origen y el del fichero
destino. En el fichero destino copiará el fichero
origen pasado todo a mayusculas.
*/

#include <stdio.h>

main(){
FILE *f1,*f2;
char nombre1[25];
char nombre2[25];
char c;
int l=1;
// Pedimos nombres
printf("Nombre fichero de texto origen: ");
gets(nombre1);
printf("Nombre fichero de texto destino: ");
gets(nombre2);
// Abrimos ficheros
f1=fopen(nombre1,"r");
if (f1==NULL){
	printf("Error: No se puede abrir %s",nombre1);
}
f2=fopen(nombre2,"w");
if (f2==NULL){
	printf("Error: No se puede abrir %s",nombre2);
}
// Copiamos f1 en f2
c=fgetc(f1);
while (c!=EOF)
	{
		fputc(toupper(c),f2);
		c=fgetc(f1);
	}
fclose(f1);fclose(f2);
// Abrimos f2 para lectura
f2=fopen(nombre2,"r");
if (f2==NULL){
	printf("Error: No se puede abrir %s",nombre2);
}
// Mostramos f2
c=fgetc(f2);
while (c!=EOF)
	{
		fputc(c,stdout);
		c=fgetc(f2);
	}
fclose(f2);

}
