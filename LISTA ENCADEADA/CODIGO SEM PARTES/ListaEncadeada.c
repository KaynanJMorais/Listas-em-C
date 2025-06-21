#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

/*Criar Lista*/
void CriarLista(NoLista **l)
{
    *l = NULL;
}

/*Verificar se a lista esta vazia*/
int EstaVazia(NoLista **l)
{
    return (*l == NULL);
}

/*Insere elemento no inicio*/
void InsereElementoInicio(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;  // info recebe valor que desejo inserir
        novo->prox = *l; // novo->prox recebe conteudo antigo da lista
        *l = novo;       // lista recebe novo elemento
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

/*Insere elemento no fim*/
void InsereElementoFim(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v; // info recebe valor que desejo inserir
        novo->prox = NULL;
        /*é o primeiro?*/
        if (EstaVazia(l))
        { // veririca se a lista esta vazia
            *l = novo;
        }
        else
        { // caso a lista nao esteja vazia
            NoLista *p;
            for (p = *l; p->prox != NULL; p = p->prox)
                ; // encontrar o ultimo elemento
            p->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!");
}

/*Insere elemento no meio*/
void InsereElementoMeio(NoLista **l, int v, int ant)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        if (EstaVazia(l))
        {
            novo->prox = NULL;
            *l = novo;
        }
        else
        {
            NoLista *p;
            for (p = *l; p->info != ant && p->prox != NULL; p = p->prox)
                ;
            if (p->info == ant)
            {
                novo->prox = p->prox;
                p->prox = novo;
            }
            else
            {
                printf("Elemento nao encontrado");
            }
        }
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

/*Imprimir lista*/
void Imprimir(NoLista **l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = *l; p != NULL; p = p->prox)
        { // enquanto
            printf("%d ", p->info);
        }
        printf("\n");
    }
    else
    {
        printf("Lista vazia");
    }
}

/*Insere Ordenado*/
void InsereOrdenado(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        if (EstaVazia(l))
        { // lista estiver vazia
            novo->prox = NULL;
            *l = novo;
        }
        else if (novo->info < (*l)->info) // caso o valor informado for menor que o primeiro
        {
            novo->prox = *l;
            *l = novo;
        }
        else
        {
            NoLista *p;
            for (p = *l; p->prox && novo->info > p->prox->info; p = p->prox)
                ; // verifica se o proximo existe, e caso for um valor menor ele insere no meio
            novo->prox = p->prox;
            p->prox = novo;
        }
    }
    else
    {
        printf("Erro ao alocar memoria");
    }
}

/*Remove todos elementos da lista*/
void LiberarLista(NoLista **l)
{
    NoLista *p;
    NoLista *temp;
    if (!EstaVazia(l))
    {
        for (p = *l; p != NULL; p = temp)
        {
            temp = p->prox;
            free(p);
        }
        *l = NULL;
    }
    else
    {
        printf("Lista vazia");
    }
}

/*Remove o elemento V da lista*/
void RemoverElemento(NoLista **l, int v)
{
    NoLista *p, *ant = NULL;
    if (!EstaVazia(l))
    {
        for (p = *l; p != NULL && p->info != v; p = p->prox)
        {
            ant = p;
        }
        if (p == NULL)
        {
            printf("Elemento não encontrado");
        }
        else
        {
            if (ant == NULL)
            { // caso for primeiro elemento
                *l = p->prox;
            }
            else
            {
                ant->prox = p->prox;
            }
        }
        free(p);
    }
}

/*Verifica se o elemento V na lista*/
NoLista *buscar(NoLista **l, int v)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = *l; p != NULL && p->info != v; p = p->prox)
            ;
        return p;
    }
    {
        return NULL;
    }
}

/*Ultimo Elemento*/
NoLista *ultimo(NoLista **l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = *l; p->prox != NULL; p = p->prox)
            ;
        return p;
    }
    else
    {
        return NULL;
    }
}

/*Calcula a quantidade de elemento*/
int QuantidadeElemento(NoLista **l)
{
    NoLista *p;
    int quantidade = 0;
    for (p = *l; p != NULL; p = p->prox)
    {
        quantidade++;
    }
    return quantidade;
}

/*Retorna os elementos maiores que n*/
int maiores(NoLista **l, int v)
{
    int cont = 0;
    NoLista *p;
    for (p = *l; p != NULL; p = p->prox)
    {
        if (p->info > v)
        {
            cont++;
        }
    }
    return cont;
}

/*Concatena duas lista, ou seja, se A = 1 2 3 e B = 4 5 6, a lista devera exibir 1 2 3 4 5 6*/
NoLista *concatena(NoLista **l1, NoLista **l2)
{
    NoLista *p;
    NoLista *ListaConcatenada = NULL;

    for (p = *l1; p != NULL; p = p->prox)
    { // copia lista 1
        InsereElementoFim(&ListaConcatenada, p->info);
    }

    for (p = *l2; p != NULL; p = p->prox)
    { // copia lista 2
        InsereElementoFim(&ListaConcatenada, p->info);
    }

    return ListaConcatenada;
}

/*Separa a lista no elemento V exemplo A = 1 2 3 4, V = 2 então nova lista = 3 4*/
NoLista *separa(NoLista **l, int v)
{
    NoLista *p, *ant = NULL;
    for (p = *l; p != NULL && p->info != v; p = p->prox) // procura o elemento
    {
        ant = p;
    }
    if (p == NULL)
    {
        return NULL;
    }

    NoLista *nova = p->prox;
    p->prox = NULL;
    return nova;
}

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
