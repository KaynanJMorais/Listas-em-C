#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "lista.h"

void main()
{
    NoLista *a, *b, *c, *d;
    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    NoLista *ult = NULL;
    int v, ant, op, opP, qntd, maior;
    char resp;
    do
    {
        printf("Em qual lista deseja mexer A ou B?\n");
        printf("1 - Menu A\t2 - Menu B\n");
        printf("3 - Concatenar Listas\t4 - Separar Listas\n");
        printf("5 - Imprimir Lista\t 0 - Sair\n");
        scanf("%d", &opP);
        printf("\n");

        switch (opP)
        {
        case 1:
        {
            do
            {
                printf("%-20s %-20s\n", "1 - Inserir Início", "2 - Inserir Meio");
                printf("%-20s %-20s\n", "3 - Inserir Fim", "4 - Inserir Ordenado");
                printf("%-20s %-20s\n", "5 - Remover Elemento", "6 - Liberar Lista");
                printf("%-20s %-20s\n", "7 - Buscar Elemento", "8 - Ultimo Elemento");
                printf("%-20s %-20s\n", "9 - Quant. Elementos", "10 - Elementos maiores que X");
                printf("%-20s\n", "0 - Sair");
                scanf("%d", &op);
                printf("\n");
                switch (op)
                {
                case 1:
                    do
                    {
                        printf("Digite o valor que deseja inserir\n");
                        scanf("%d", &v);
                        InsereElementoInicio(&a, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 2:
                    do
                    {
                        printf("Digite o valor que deseja inserir e um valor do meio que deseja colocar lo entre\n");
                        scanf("%d %d", &v, &ant);
                        InsereElementoMeio(&a, v, ant);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 3:
                    do
                    {
                        printf("Digite o valor que deseja inserir:\n");
                        scanf("%d", &v);
                        InsereElementoFim(&a, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 4:
                    do
                    {
                        printf("Digite o valor que deseja inserir\n");
                        scanf("%d", &v);
                        InsereOrdenado(&a, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 5:
                    do
                    {
                        printf("Digite o valor que deseja remover\n");
                        scanf("%d", &v);
                        RemoverElemento(&a, v);
                        printf("Deseja remover outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 6:
                    LiberarLista(&a);
                    break;
                case 7:
                    do
                    {
                        printf("Digite o valor que deseja buscar:\n");
                        scanf("%d", &v);
                        NoLista *b = buscar(&a, v);
                        if (b != NULL)
                        {
                            printf("O valor %d foi encontrado\n", v);
                        }
                        else
                        {
                            printf("O valor %d não foi encontrado\n", v);
                        }
                        printf("Deseja buscar outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 8:
                    ult = ultimo(&a);
                    if (ult != NULL)
                    {
                        printf("Último Elemento: %d\n", ult->info);
                    }
                    else
                    {
                        printf("A lista está vazia\n");
                    }
                    break;
                case 9:
                    qntd = QuantidadeElemento(&a);
                    printf("Quantidade de elementos: %d\n", qntd);
                    break;
                case 10:
                    printf("Digite um valor e verifique quantos outros maiores que eles existem na lista:\n");
                    scanf("%d", &v);
                    maior = maiores(&a, v);
                    printf("Quantidade de elemento maior que %d: %d \n", v, maior);
                    break;
                default:
                    break;
                }
            } while (op != 0);
            system("cls");
        }
        break;
        case 2:
        {
            do
            {
                printf("%-20s %-20s\n", "1 - Inserir Início", "2 - Inserir Meio");
                printf("%-20s %-20s\n", "3 - Inserir Fim", "4 - Inserir Ordenado");
                printf("%-20s %-20s\n", "5 - Remover Elemento", "6 - Liberar Lista");
                printf("%-20s %-20s\n", "7 - Buscar Elemento", "8 - Ultimo Elemento");
                printf("%-20s %-20s\n", "9 - Quant. Elementos", "10 - Elementos maiores que X");
                printf("%-20s\n", "0 - Sair");
                scanf("%d", &op);
                printf("\n");
                switch (op)
                {
                case 1:
                    do
                    {
                        printf("Digite o valor que deseja inserir\n");
                        scanf("%d", &v);
                        InsereElementoInicio(&b, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 2:
                    do
                    {
                        printf("Digite o valor que deseja inserir e um valor do meio que deseja colocar lo entre\n");
                        scanf("%d %d", &v, &ant);
                        InsereElementoMeio(&b, v, ant);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 3:
                    do
                    {
                        printf("Digite o valor que deseja inserir:\n");
                        scanf("%d", &v);
                        InsereElementoFim(&b, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 4:
                    do
                    {
                        printf("Digite o valor que deseja inserir\n");
                        scanf("%d", &v);
                        InsereOrdenado(&b, v);
                        printf("Deseja inserir outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 5:
                    do
                    {
                        printf("Digite o valor que deseja remover\n");
                        scanf("%d", &v);
                        RemoverElemento(&b, v);
                        printf("Deseja remover outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 6:
                    LiberarLista(&b);
                    printf("\n");
                    break;
                case 7:
                    do
                    {
                        printf("Digite o valor que deseja buscar:\n");
                        scanf("%d", &v);
                        NoLista *b = buscar(&b, v);
                        if (b != NULL)
                        {
                            printf("O valor %d foi encontrado\n", v);
                        }
                        else
                        {
                            printf("O valor %d não foi encontrado\n", v);
                        }
                        printf("Deseja buscar outro? (S - sim , N - nao)\n");
                        scanf(" %c", &resp); // espaço antes do %c para evitar ler o \n
                    } while (resp == 's' || resp == 'S');
                    system("cls");
                    break;
                case 8:
                    ult = ultimo(&b);
                    if (ult != NULL)
                    {
                        printf("Último Elemento: %d\n", ult->info);
                    }
                    else
                    {
                        printf("A lista está vazia\n");
                    }
                    break;
                case 9:
                    qntd = QuantidadeElemento(&b);
                    printf("Quantidade de elementos: %d\n", qntd);
                    break;
                case 10:
                    printf("Digite um valor e verifique quantos outros maiores que eles existem na lista:\n");
                    scanf("%d", &v);
                    maior = maiores(&b, v);
                    printf("Quantidade de elemento maior que %d: %d \n", v, maior);
                    break;
                default:
                    break;
                }
            } while (op != 0);
            system("cls");
        }
        break;
        case 3:
            c = concatena(&a, &b);
            printf("\n");
            break;
        case 4:
            printf("Deseja separar qual lista para criar a nova lista separada?\n");
            printf("1 - A\t2 - B\n");
            scanf("%d", &opP);
            switch (opP)
            {
            case 1:
                printf("Deseja separar a lista em qual numero?\n");
                scanf("%d", &v);
                d = separa(&a, v);
                printf("\n");
                break;
            case 2:
                printf("Deseja separar a lista em qual numero?\n");
                scanf("%d", &v);
                d = separa(&b, v);
                printf("\n");
                break;
            default:
                break;
            }
            break;
        case 5:
            printf("LISTA A:\n");
            Imprimir(&a);
            printf("\n");
            printf("LISTA B:\n");
            Imprimir(&b);
            printf("\n");
            printf("LISTA CONCATENADA:\n");
            Imprimir(&c);
            printf("\n");
            printf("LISTA SEPARADA:\n");
            Imprimir(&d);
            printf("\n");
            break;
        default:
            break;
        }
    } while (opP != 0);
}
