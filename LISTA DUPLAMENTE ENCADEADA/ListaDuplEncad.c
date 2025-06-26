#include <stdlib.h>
#include <stdio.h>

typedef struct nolista
{
    int info;
    struct nolista *prox;
    struct nolista *ant;
} NoLista;

void CriaLista(NoLista **l)
{
    *l = NULL;
}

int EstaVazia(NoLista **l)
{
    return (*l == NULL);
}

void InsereElementoInicio(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = *l;
        novo->ant = NULL;
        if (*l != NULL)
        {
            (*l)->ant = novo;
        }
        *l = novo;
    }
    else
    {
        printf("Memória insuficiente!\n");
    }
}

void InsereElementoFim(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    NoLista *p;
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = NULL;
        if (EstaVazia(l))
        {
            novo->ant = NULL;
            *l = novo;
        }
        else
        {
            for (p = *l; p->prox != NULL; p = p->prox)
                ;
            p->prox = novo;
            novo->ant = p;
        }
    }
    else
    {
        printf("Memória insuficiente!\n");
    }
}

void imprimir(NoLista **l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = *l; p != NULL; p = p->prox)
        {
            printf("%d ", p->info);
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

void imprimeInversa(NoLista **l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = *l; p->prox != NULL; p = p->prox) // P recebe o ultimo elemento
            ;
        for (; p != NULL; p = p->ant) // P começa no ultimo e percorre ate o começo da lista
        {
            printf("%d ", p->info); // Imprime o valor do nó inverso
        }
    }
    else
    {
        printf("Lista Vazia!");
    }
}

void insereOrdenado(NoLista **l, int v)
{
    NoLista *p, *ant = NULL;
    for (p = *l; p != NULL; p = p->prox) // Percorre a lista
    {
        ant = p; // Anterior recebe o nó atual
    }
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista)); // Aloca memoria para o novo nó
    if (novo != NULL)                                   // Verifica se alocou
    {
        novo->info = v;  // Coloca o valor no nó
        novo->ant = ant; // Nó novo recebe o antecessor
        novo->prox = p;  // Nó novo recebe o proximo nó

        if (p != NULL) // Se o nó atual não for NULL
        {
            p->ant = novo; // Nó atual recebe o nó novo como antecessor
        }
        if (ant == NULL) // Se o antecessor for NULL
        {
            *l = novo; // Nó novo se torna o primeiro da lista
        }
        else
        {
            ant->prox = novo; // Nó anterior recebe o nó novo como proximo
        }
    }
    else
    {
        printf("Memoria Insuficiente!");
    }
}

NoLista *Separa(NoLista **l, int v)
{
    NoLista *p;
    NoLista *novo;
    for (p = *l; p != NULL && p->info != v; p = p->prox) // Percorre a lista até encontrar o valor
        ;
    if (p == NULL) // Se não encontrar o valor
    {
        return NULL; // Retorna NULL
    }
    novo = p->prox; // Nó novo recebe o proximo nó do nó encontrado
    p->prox = NULL; // Nó encontrado recebe NULL como proximo
    return novo;
}

NoLista *concatena(NoLista **l1, NoLista **l2)
{
    if (EstaVazia(l1)) // Se a lista 1 estiver vazia
    {
        *l1 = *l2;  // Lista 1 recebe a lista 2
        return *l1; // Retorna a lista 1
    }
    if (EstaVazia(l2))
    {
        return *l1; // Retorna a lista 1
    }
    NoLista *p;
    for (p = *l1; p->prox != NULL; p = p->prox) // Percorre a lista 1 até o último nó
        ;
    p->prox = *l2; // p recebe a lista 2
    return *l1;    // Retorna a lista 1
}

NoLista *impar(NoLista **l)
{
    NoLista *p;
    NoLista *nova = NULL;
    for (p = *l; p != NULL; p = p->prox) // Percorre a lista
    {
        if (p->info % 2 != 0) // Se o valor for impar
        {
            NoLista *novo = (NoLista *)malloc(sizeof(NoLista)); // Aloca memória para o novo nó
            if (novo != NULL)                                   // Se a alocação foi bem sucedida
            {
                novo->info = p->info; // O novo nó recebe o valor do nó atual
                novo->prox = nova;    // O novo nó recebe o nó anterior
                novo->ant = NULL;     // O novo nó recebe NULL como antecessor
                if (nova != NULL)     // Se a lista não está vazia
                {
                    nova->ant = novo; // O nó anterior recebe o novo nó como antecessor
                }
                nova = novo; // A lista de impares recebe o novo nó
            }
        }
    }
    return nova;
}

int main()
{
    NoLista *a = NULL;
    NoLista *b = NULL;
    NoLista *p;
    CriaLista(&a);
    CriaLista(&b);
    InsereElementoInicio(&a, 1);
    InsereElementoInicio(&a, 2);
    InsereElementoInicio(&a, 3);
    InsereElementoInicio(&a, 4);
    InsereElementoFim(&b, 5);
    InsereElementoFim(&b, 6);
    InsereElementoFim(&b, 7);
    p = impar(&a);
    imprimir(&p);
    return 0;
}