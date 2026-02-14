/* 
Agenda con listas simples y ficheros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCADENA 200

enum { Ver=1, Alta, Buscar, Salir };

struct Entrada {
  char * nombre;
  char * direccion;
  char * telefono;
};

struct NodoAgenda {
  struct Entrada datos;
  struct NodoAgenda * sig;
};

typedef struct NodoAgenda * TipoAgenda;

void quita_fin_de_linea(char linea[])
{
  int i;
  for (i=0; linea[i] != '\0'; i++)
    if (linea[i] == '\n') {
      linea[i] = '\0';
      break;
    }
}

void muestra_entrada(struct NodoAgenda * e)
  // Podríamos haber pasado e por valor, pero resulta más eficiente 
  // /y no mucho más
  // incómodo) hacerlo por referencia: 
  //pasamos así sólo 4 bytes en lugar de 12.
{
  printf("Nombre   : %s\n", e->datos.nombre);
  printf("Dirección: %s\n", e->datos.direccion);
  printf("Teléfono : %s\n", e->datos.telefono);
}

void libera_entrada(struct NodoAgenda * e)
{
  int i;

  free(e->datos.nombre);
  free(e->datos.direccion);
  free(e->datos.telefono);
  free(e);
}


TipoAgenda crea_agenda(void)
{
  return NULL;
}

struct NodoAgenda * buscar_entrada_por_nombre(TipoAgenda agenda, char nombre[])
{
  struct NodoAgenda * aux;

  for (aux = agenda; aux != NULL; aux = aux->sig)
    if (strcmp(aux->datos.nombre, nombre) == 0) 
      return aux;

  return NULL;
}


TipoAgenda anyadir_entrada(  TipoAgenda agenda, char nombre[], 
                             char direccion[], char telefono[])
{
  struct NodoAgenda * aux, * e;

  /* Averiguar si ya tenemos una persona con ese nombre */
  if (buscar_entrada_por_nombre(agenda, nombre)  != NULL)
    return agenda;

  /* Si llegamos aquí, es porque no teníamos registrada a esa persona. */
  e = malloc(sizeof(struct NodoAgenda));
  e->datos.nombre = malloc((strlen(nombre)+1)*sizeof(char));
  strcpy(e->datos.nombre, nombre);
  e->datos.direccion = malloc((strlen(direccion)+1)*sizeof(char));
  strcpy(e->datos.direccion, direccion);
  e->datos.telefono = malloc((strlen(telefono)+1)*sizeof(char));
  strcpy(e->datos.telefono, telefono);  
  e->sig = agenda;
  agenda = e;
  return agenda;
}

void muestra_agenda(TipoAgenda agenda)
{
  struct NodoAgenda * aux;

  for (aux = agenda; aux != NULL; aux = aux->sig)
    muestra_entrada(aux);
}


void libera_agenda(TipoAgenda agenda)
{
  struct NodoAgenda * aux, *siguiente;

  aux = agenda;
  while (aux != NULL) {
    siguiente = aux->sig;
    libera_entrada(aux);
    aux = siguiente;
  }
}

void escribe_agenda(TipoAgenda agenda, char nombre_fichero[])
{
  struct NodoAgenda * aux;
  FILE * fp;
  
  fp = fopen(nombre_fichero, "w");
  for (aux=agenda; aux!=NULL; aux=aux->sig) 
    fprintf(fp, "%s\n%s\n%s\n",   aux->datos.nombre, 
                                      aux->datos.direccion, 
                                      aux->datos.telefono);
  fclose(fp);
}

TipoAgenda lee_agenda(char nombre_fichero[])
{
  TipoAgenda agenda;
  struct Entrada * entrada_leida;  
  FILE * fp;
  char nombre[MAXCADENA+1], direccion[MAXCADENA+1], telefono[MAXCADENA+1];
  int longitud;
  
  agenda = crea_agenda();

  fp = fopen(nombre_fichero, "r");
  if (fp!=NULL) // Si hay fichero
  {
  while (1) {
    fgets(nombre, MAXCADENA, fp);
    if (feof(fp)) break; // Si se acabó el fichero,  acabar la lectura.
    quita_fin_de_linea(nombre);

    fgets(direccion, MAXCADENA, fp);
    quita_fin_de_linea(direccion);

    fgets(telefono, MAXCADENA, fp);
    quita_fin_de_linea(telefono);
    
    agenda = anyadir_entrada(agenda, nombre, direccion, telefono);
  }
  fclose(fp);
  } // if
  return agenda;
}



/************************************************************************
 * Programa principal
 ************************************************************************/

int main(void) 
{
  TipoAgenda miagenda;
  struct NodoAgenda * encontrada;
  int opcion;
  char nombre[MAXCADENA+1];
  char direccion[MAXCADENA+1];
  char telefono[MAXCADENA+1];
  char linea[MAXCADENA+1];

  miagenda = lee_agenda("agenda.txt");
  do {
    printf("Menú:\n");
    printf("1) Ver contenido completo de la agenda.\n");
    printf("2) Dar de alta una persona.\n");
    printf("3) Buscar teléfonos de una persona.\n");
    printf("4) Salir.\n");
    printf("Opción: "); 
    gets(linea); sscanf(linea, "%d", &opcion);
    
    switch(opcion) {

      case Ver:
        muestra_agenda(miagenda);
        break;

      case Alta:
        printf("Nombre   : "); gets(nombre);    
        printf("Dirección: "); gets(direccion); 
        printf("Teléfono : "); gets(telefono);  
        miagenda = anyadir_entrada(miagenda, nombre, direccion, telefono);
        break;

      case Buscar:
        printf("Nombre: "); gets(nombre);
        encontrada = buscar_entrada_por_nombre(miagenda, nombre);
        if (encontrada == NULL) 
          printf("No hay nadie llamado %s en la agenda.\n", nombre);
        else 
          muestra_entrada(encontrada);
        break;
    }
  } while (opcion != Salir);

  escribe_agenda(miagenda, "agenda.txt");
  libera_agenda(miagenda);

  return 0;
}
