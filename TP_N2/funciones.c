#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


void inicializarEstado(ePersona persona[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        persona[i].estado=0;
    }
}
int buscarLibre(ePersona persona[],int tam)
{
    int indice=-1;
        for(int i=0;i<tam;i++)
        {
            if(persona[i].estado==0)
            {
                indice=i;
                break;
            }
        }
        return indice;

}
int buscarPersona(int dni,ePersona persona[],int tam)
{
    int dnix=-1;
        for(int i=0;i<tam;i++)
        {
            if(persona[i].dni==dni&&persona[i].estado==1)
            {
                dnix=i;
                break;
            }
        }
        return dnix;
}
int esNumero(char str[])
{
  int cont = 0;

    while(str[cont] != '\0')
    {
     if((str[cont]<'0'||str[cont]>'9'))
      {
        return 0;
      }
      cont++;
    }
  return 1;
}

int esLetra(char str[])
{
  int cont = 0;
  while(str[cont] != '\0')
  {
     if((str[cont] != ' ')&&(str[cont]<'a'||str[cont]>'z')&&(str[cont]<'A'||str[cont]>'Z'))
      {
        return 0;
      }
      cont++;
  }
  return 1;
}
void mostrarPersona(ePersona persona)
{
    printf(" %s\t\t%d\t%d\n",persona.nombre,persona.dni,persona.edad);
}
void mostrarLasPersonas(ePersona persona[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        if(persona[i].estado==1)
        {
            mostrarPersona(persona[i]);
        }
    }
}
void ordenarporNombre(ePersona persona[],int tam)
{
    ePersona aux;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                aux=persona[i];
                persona[i]=persona[j];
                persona[j]=aux;
            }
        }
    }
}

void inicializaVectorEdades(char vec1[],char vec2[],char vec3[],char caracter,int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        vec1[i] = caracter;
        vec2[i] = caracter;
        vec3[i] = caracter;
    }
}
void BorrarAsteriscos(char vec[], int x, int y)
{
    int i;
    int aux = y - x;
    for(i=0;i<aux;i++)
    {
       vec[i] = ' ';
    }
}

void ImprimeGrafico(char men18[],char e19_35[],char may35[],int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("%c\t%c\t%c\n",men18[i],e19_35[i],may35[i]);
    }
    printf("<18\t18-35\t>35\n\n");
}
