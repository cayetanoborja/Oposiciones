/* numerolineas.c
Hacer un programa en C, que imprima por pantalla
el contenido del fichero de texto cuyo nombre
sea introducido por teclado. 
Las lineas del fichero las numerara.
*/

#include <stdio.h>

main(){
FILE *f;
char nombre[25];
char c;
int l=1;

printf("Nombre fichero de texto: ");
gets(nombre);

f=fopen(nombre,"r");
if (f==NULL){
	printf("Error: No se puede abrir");
}
else
{
	c=fgetc(f);
	while (c!=EOF)
	{
		fputc(c,stdout);
		if (c=='\n') {
			printf("%d",l); l++;
			}
		c=fgetc(f);
	}
	printf("Fin fichero\n");
}
fclose(f);
}
