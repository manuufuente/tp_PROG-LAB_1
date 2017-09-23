#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


#define TAM 6



int main()
{
    ePersona Personas[TAM];


    char seguir='s',borrar;
    char dni[50],nombre[50],edad[50],men_18[TAM],edad19_35[TAM],may_36[TAM];
    int opcion=0,idc,dnix,idcx,edadx,cant;
    int cont_18;
    int cont19_35;
    int cont_36;



    inicializarEstado(Personas,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        system("cls");

        while(opcion<1||opcion>5)
        {
            printf("\n\nOpcion incorrecta. Reingrese una opcion: ");
            scanf("%d",&opcion);
            system("cls");
        }




        switch(opcion)
        {
            case 1:
                idc=buscarLibre(Personas,TAM);
                if(idc==-1)
                    {
                    printf("EL SISTEMA ESTA LLENO.\n");
                    system("pause");
                    system("cls");
                    break;
                    }
                 printf("Ingrese DNI:");
                 fflush(stdin);
                 gets(dni);
                 system("cls");
                    while(!esNumero(dni))
                    {
                        printf("El DNI debe ser solo numeros. Reingrese DNI: ");
                        fflush(stdin);
                        gets(dni);
                        system("cls");
                    }
                    dnix=atoi(dni);
                    idcx=buscarPersona(dnix,Personas,TAM);
                    if(idcx!=-1)
                    {
                        printf("Esta persona ya fue cargada.\n\n");
                        printf("-------------------------------------------\n");
                         printf("APELLIDO Y NOMBRE\t DNI\t\t EDAD\n\n");

                        mostrarPersona(Personas[idcx]);
                        system("pause");
                        system("cls");
                        break;
                    }else
                        {

                            printf("Ingrese Apellido y nombre:");
                            fflush(stdin);
                            gets(nombre);
                            system("cls");
                             while(!esLetra(nombre))
                                {
                                    printf("El nombre debe ser solo letras. Reingrese nombre: ");
                                    fflush(stdin);
                                    gets(nombre);
                                    system("cls");
                                }

                                strlwr(nombre);
                                nombre[0]=toupper(nombre[0]);
                                cant=strlen(nombre);
                                for(int i=0;i<cant;i++)
                                {
                                    if(nombre[i]==' ')
                                    {
                                        nombre[i+1]=toupper(nombre[i+1]);
                                    }
                                }

                            printf("Ingrese edad:");
                            fflush(stdin);
                            gets(edad);
                            system("cls");
                            while(!esNumero(edad))
                            {
                                printf("La edad debe ser solo numeros. Reingrese edad: ");
                                fflush(stdin);
                                gets(edad);
                                system("cls");
                            }
                            edadx=atoi(edad);

                        }

                        Personas[idc].dni=dnix;
                        Personas[idc].edad=edadx;
                        strcpy(Personas[idc].nombre,nombre);
                        Personas[idc].estado=1;
                        system("cls");


                break;
            case 2:
                ordenarporNombre(Personas,TAM);
                printf("------------------------------------------\n");
                printf("APELLIDO Y NOMBRE\t DNI\t\tEDAD\n");
                mostrarLasPersonas(Personas,TAM);
                printf("\n\n");
                printf("-------------------------------------------\n\n\n\n");


                printf("Ingrese DNI:");
                fflush(stdin);
                gets(dni);
                system("cls");
                    while(!esNumero(dni))
                    {
                        printf("El DNI debe ser solo numeros. Reingrese DNI: ");
                        fflush(stdin);
                        gets(dni);
                        system("cls");
                    }
                    dnix=atoi(dni);
                    idcx=buscarPersona(dnix,Personas,TAM);
                    if(idcx!=-1)
                    {
                        printf("APELLIDO Y NOMBRE\t DNI\t\t EDAD\n\n");

                        mostrarPersona(Personas[idcx]);

                        printf("\n\n ¿Desea eliminar esta persona?(s/n): ");
                        fflush(stdin);
                        scanf("%c",&borrar);
                        while(borrar!='n'&&borrar!='s')
                        {
                            printf("\nOpcion incorrecta. Reingrese (s/n):");
                            fflush(stdin);
                            scanf("%c",&borrar);
                        }
                        if(borrar=='s')
                        {
                            Personas[idcx].estado=0;
                            printf("\n\nLa persona ha sido borrada...\n\n\n\n");
                            system("pause");
                            system("cls");
                            break;
                        }else
                            {
                                printf("\nLa persona NO será borrada...\n\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                        }

                break;
            case 3:
                ordenarporNombre(Personas,TAM);
                printf("------------------------------------------\n");
                printf("APELLIDO Y NOMBRE\t DNI\t\tEDAD\n");
                mostrarLasPersonas(Personas,TAM);
                printf("\n\n");
                printf("-------------------------------------------\n");
                system("pause");
                system("cls");
                break;
            case 4:
                cont_18=0;
                cont19_35=0;
                cont_36=0;

                for(int i=0;i<TAM;i++)
                {
                    if(Personas[i].estado == 1)
                        {
                            if ((Personas[i].edad >= 18 && Personas[i].edad <= 35))
                                {
                                    cont19_35++;
                                }else
                                    {
                                        if(Personas[i].edad < 18)
                                            {
                                                cont_18++;
                                            }else
                                                {
                                                    cont_36++;
                                                }
                                    }
                        }
                }

                inicializaVectorEdades(men_18,edad19_35,may_36,'*',TAM);
                BorrarAsteriscos(men_18,cont_18,TAM);
                BorrarAsteriscos(edad19_35,cont19_35,TAM);
                BorrarAsteriscos(may_36,cont_36,TAM);
                printf("--------------------------------------\n");
                ImprimeGrafico(men_18,edad19_35,may_36,TAM);
                printf("--------------------------------------\n\n");
                system("pause");
                system("cls");


                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

