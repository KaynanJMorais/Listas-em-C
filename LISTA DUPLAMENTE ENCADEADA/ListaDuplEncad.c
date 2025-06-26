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
        for (p = *l; p->prox != NULL; p = p->prox)
            ;
        for (; p != NULL; p = p->ant)
        {
            printf("%d ", p->info);
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
    for (p = *l; p != NULL; p = p->prox)
    {
        ant = p;
    }
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->ant = ant;
        novo->prox = p;

        if (p != NULL)
        {
            p->ant = novo;
        }
        if (ant == NULL)
        {
            *l = novo;
        }
        else
        {
            ant->prox = novo;
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
    for (p = *l; p != NULL && p->info != v; p = p->prox)
        ;
    if (p == NULL)
    {
        return NULL;
    }
    novo = p->prox;
    p->prox = NULL;
    return novo;
}

NoLista *concatena(NoLista **l1, NoLista **l2)
{
    if (EstaVazia(l1))
    {
        *l1 = *l2;
        return *l1;
    }
    if (EstaVazia(l2))
    {
        return *l1;
    }
    NoLista *p;
    for (p = *l1; p->prox != NULL; p = p->prox)
        ;
    p->prox = *l2;
    return *l1;
}

NoLista *impar(NoLista **l)
{
    NoLista *p;
    NoLista *nova = NULL;
    for (p = *l; p != NULL; p = p->prox)
    {
        if (p->info % 2 != 0)
        {
            NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
            if (novo != NULL)
            {
                novo->info = p->info;
                novo->prox = nova;
                novo->ant = NULL;
                if (nova != NULL)
                {
                    nova->ant = novo;
                }
                nova = novo;
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