#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s',aux[10],auxA[10],auxB[10];
    int opcion,flagA=0,flagB=0,a,b,suma,resta,multi,fac,auxNum;
    float div;

    while(seguir=='s')
    {   opcion=0;
        if(flagA==1)
        {
            printf("1- Ingresar 1er operando (A=%d)\n",a);
        }else{
                printf("1- Ingresar 1er operando (A=x)\n");
             }
        if(flagB==1)
        {
            printf("2- Ingresar 2do operando (B=%d)\n",b);
        }else{
                printf("2- Ingresar 2do operando (B=y)\n");
             }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\nIngrese una opcion: ");
        fflush(stdin);
        gets(aux);
        system("cls");
            if(esNumero(aux)){
            auxNum=atoi(aux);
                            }
                        else{
                            printf("La opcion ingresada no es valida.Reingrese...\n\n");
                            system("pause");
                            system("cls");
                            }
            if(auxNum<10&&auxNum>0)
            {
                opcion=auxNum;
            }else{
                            printf("La opcion ingresada no es valida.Reingrese...\n\n");
                            system("pause");
                            system("cls");
                            }



        switch(opcion)
        {
            case 1:
                printf("Ingresar primer operando: ");
                fflush(stdin);
                gets(auxA);
                system("cls");
                if(esNumero(auxA))
                    {
                    a=atoi(auxA);
                    flagA=1;
                    }
                else{
                        printf("El valor ingresado no es un numero..\n\n");
                        system("pause");
                        system("cls");
                    }



                break;
            case 2:
                printf("Ingresar segundo operando: ");
                fflush(stdin);
                gets(auxB);
                system("cls");
                if(esNumero(auxB))
                    {
                    b=atoi(auxB);
                    flagB=1;
                    }
                else{
                        printf("El valor ingresado no es un numero..\n\n");
                        system("pause");
                        system("cls");
                    }
                break;
            case 3:
                if(flagA==1&&flagB==1)
                {
                    suma=sumar(a,b);
                    printf("La suma es : %d\n",suma);
                    system("pause");
                    system("cls");
                }else{
                        printf("No has ingresado ambos numeros.\n");
                        system("pause");
                        system("cls");
                     }


                break;
            case 4:
                if(flagA==1&&flagB==1)
                {
                    resta=restar(a,b);
                    printf("La resta es : %d\n",resta);
                    system("pause");
                    system("cls");
                }else{
                        printf("No has ingresado ambos numeros.\n");
                        system("pause");
                        system("cls");
                     }
                break;
            case 5:
                if(flagA==1&&flagB==1)
                {
                       if(b!=0)
                       {
                           div=dividir(a,b);
                           printf("La divicion es : %.2f \n",div);
                           system("pause");
                           system("cls");
                       }else{
                                printf("No puede dividir un numero por 0.\n");
                                system("pause");
                                system("cls");
                            }
                }else{
                        printf("No has ingresado ambos numeros.\n");
                        system("pause");
                        system("cls");
                     }

                break;
            case 6:
                    if(flagA==1&&flagB==1)
                {
                    multi=multiplicar(a,b);
                    printf("La multiplicaion es : %d\n",multi);
                    system("pause");
                    system("cls");
                }else{
                        printf("No has ingresado ambos numeros.\n");
                        system("pause");
                        system("cls");
                     }
                break;
            case 7:if(flagA==1)
                {
                    fac=factorial(a);
                    printf("El factorial de A es: %d\n",fac);
                    system("pause");
                    system("cls");

                }else{
                        printf("No has ingresado el primer numero.\n");
                        system("pause");
                        system("cls");
                     }

                break;
            case 8:
                if(flagA==1&&flagB==1)
                {
                    suma=sumar(a,b);
                    resta=restar(a,b);

                    printf("*La suma es : %d\n\n",suma);
                    printf("*La resta es : %d\n\n",resta);

                    if(b!=0)
                       {
                           div=dividir(a,b);
                           printf("*La divicion es : %.2f \n\n",div);

                       }else{
                           printf("*La divicion es : NO SE PUDE DIVIDIR POR 0 \n\n");
                            }
                    multi=multiplicar(a,b);
                    printf("*La multiplicaion es : %d\n\n",multi);

                }else{
                        printf("*La suma es : NO FUERON INGRESADOS AMBOS NUMEROS\n\n",suma);
                        printf("*La resta es : NO FUERON INGRESADOS AMBOS NUMEROS\n\n",resta);
                        printf("*La divicion es : NO FUERON INGRESADOS AMBOS NUMEROS \n\n",div);
                        printf("*La multiplicaion es : NO FUERON INGRESADOS AMBOS NUMEROS\n\n");

                     }

                     if(flagA==1)
                     {
                        fac=factorial(a);
                        printf("*El factorial es: %d\n\n",fac);
                     }else{
                                printf("*El factorial es: NO SE INGRESO EL PRIMER NUMERO\n\n");
                            }
                        system("pause");
                        system("cls");
                break;
            case 9:
                seguir = 'n';

                break;

        }

    }
    return 0;
}

