#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

void CriarLista(NoLista **l)
{
    *l = NULL;
}

int estavazia(NoLista **l)
{
    return (*l == NULL);
}

void InserirElemento(NoLista **l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }
    else
    {
        printf("Memória insuficiente.\n");
    }
}

NoLista *Ultimo(NoLista **l)
{
    NoLista *p;
    if (!estavazia(l))
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

void imprimeRecursiva(NoLista **l)
{
    if (!estavazia(l))
    {
        NoLista *p = *l;
        printf("%d", p->info);
        imprimeRecursiva(&p->prox);
    }
}

void imprimeInverso(NoLista **l)
{
    if (!estavazia(l))
    {
        imprimeInverso(&(*l)->prox);
        printf("%d", (*l)->info);
    }
}

void liberarListaRecursiva(NoLista **l)
{
    if (!estavazia(l))
    {
        NoLista *p = *l;
        liberarListaRecursiva(&p->prox);
        free(p);
        *l = NULL;
    }
}

void removerElementoRecursiva(NoLista **l, int v)
{
    NoLista *p = *l;
    if (!estavazia(l))
    {
        if (p->info == v)
        {
            *l = p->prox;
            free(p);
        }
        else
        {
            removerElementoRecursiva(&p->prox, v);
        }
    }
}

void main()
{
    NoLista *l;
    CriarLista(&l);
    InserirElemento(&l, 1);
    InserirElemento(&l, 2);
    InserirElemento(&l, 3);
    InserirElemento(&l, 4);
    removerElementoRecursiva(&l, 3);
    if (estavazia(&l))
        printf("Lista vazia.\n");
    else
        imprimeRecursiva(&l);
    printf("\n");
}