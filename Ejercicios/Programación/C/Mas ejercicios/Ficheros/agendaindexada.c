/* agenda-indexada.c
Hacer una agenda indexada ordenada usando un fichero binario
Los registros indexaran por el campo numero.
El registro numero 1, se grabara el principio,
despues el 2, y asi sucesivamente.
Podran rellenarse registros de forma aleatoria.
*/

#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // strlen
typedef struct
{
	char numero[5];
	char nombre[20];
	char telefono[15];
	char email[20];
} registro;

#define NOMBRE "indexada.dat"
#define T sizeof(registro)
#define MAXLINEA 80

// ************************
// Coge la opcion del menu
int menu (void)
{
	char linea[MAXLINEA];
	int op;
	do {
		printf ("**************\n");
		printf ("Menu agenda con ficheros binarios indexados\n");
		printf("Bytes ocupa el fichero: %d\n",bytes());
		printf ("0. Salir\n");
		printf ("1. Alta de Registros\n");
		printf ("2. Listados Resgristros\n");
		printf ("3. Borrado de Registros\n");
		printf ("4. Mostrar registro por codigo\n");
		printf ("5. Borrar Fichero\n");
		printf ("Opcion?: ");
		gets (linea);
		sscanf (linea, "%d", &op);
	} while (op < 0 || op > 5);
	return op;
}
// ***************************
// Lee un registro por teclado
void leerregistro (registro *r){
	printf ("Numero: ");
	gets (r->numero);
	printf ("Nombre: ");
	gets (r->nombre);
	printf ("Telefono: ");
	gets (r->telefono);
	printf ("Email: ");
	gets (r->email);
}
	
// *****************************************
// Damos alta registros ordenador por numero
void alta (){
FILE *f;
registro r;
int seguir=1,res='s',pos=0;
char linea[MAXLINEA];

f=fopen(NOMBRE,"rb+");
// En modo ab+ solo anyade secuencialmente.
if (f==NULL)
  printf("Error: No se pudo abrir para lectura %s\n",NOMBRE);

printf ("**************\n");
printf ("Alta de registros de la agenda\n");

 while (seguir) {
 leerregistro(&r);
 pos = atoi(r.numero)-1;
 fseek(f,pos*T,SEEK_SET);
 fwrite(&r,T,1,f);
	 
 printf("Seguir? (s/n): ");
 gets(linea); sscanf(linea,"%c",&res);
 seguir = (res!='n');
 }
fclose(f);
}
// *******************************
// Imprime en pantalla el registro
void escriberegistro(registro r)
{
printf ("Numero   : %s\n", r.numero);
printf ("Nombre   : %s\n", r.nombre);
printf ("Telefono : %s\n", r.telefono);
printf ("Email    : %s\n", r.email);
}

// *************************
// Listado completo de la agenda
void listado (){
FILE *f;
registro r;
	
f = fopen(NOMBRE,"rb");
if (f==NULL)
  printf("Error: No se pudo abrir para lectura %s\n",NOMBRE);

printf ("**************\n");
printf ("Listado de la agenda\n");

while ( fread(&r,T,1,f)  ) 
   if (strlen(r.numero)>0) 
      escriberegistro(r); 
fclose(f);
}

// *************************
// Pone a blanco numero
void ablanco (registro *r)
{
r->numero[0]='\0';
}

// ***********************************
// Nos da la talla en bytes del fichero
int bytes(){
FILE *f;
unsigned t;
f=fopen (NOMBRE,"rb");
fseek(f,0L,SEEK_END);
t=ftell(f);
fclose(f);
return t;
}

// *************************
// Borra el contenido del fichero
void borrarf(){
FILE *f;
f=fopen (NOMBRE,"wb");
fclose(f);
}
// *************************
// Borra en registro indicado
void borrar (){
FILE *f;
registro r;
char n[3];
int pos=0;

f = fopen(NOMBRE,"rb+");
if (f==NULL)
  printf("Error: No se pudo abrir para lectura %s\n",NOMBRE);

printf ("Codigo a borrar:");gets(n);
ablanco(&r);
pos = atoi(n)-1;
fseek(f,pos*T ,SEEK_SET);
fwrite(&r,T,1,f);
fclose(f);
}

// *************************
// Busca el registro indicado
void buscar (){
FILE *f;
registro r;
int pos=0;
char n[3];

f = fopen(NOMBRE,"rb");
if (f==NULL)
  printf("Error: No se pudo abrir para lectura %s\n",NOMBRE);

printf ("Codigo a buscar:");gets(n);

pos = atoi(n)-1;
fseek(f,T*pos,SEEK_SET);
fread(&r,T,1,f);
escriberegistro(r);
fclose(f);
}

// *************************
// MAIN
main ()
{
int opcion;
do {
	opcion = menu ();
	switch (opcion) {
	case 1:
		alta();
		break;
	case 2:
		listado();
		break;
	case 3:
		borrar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrarf();
		break;
	}
} while (opcion != 0);
}
