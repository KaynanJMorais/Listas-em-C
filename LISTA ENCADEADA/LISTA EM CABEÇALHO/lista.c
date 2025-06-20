#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

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
        {
            return p;
        }
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
    NoLista *p;
    NoLista *ListaSeparada = NULL; // Criação Lista nova
    for (p = *l; p != NULL; p = p->prox)
    {
        InsereElementoFim(&ListaSeparada, p->info); // for apenas para copiar a lista Separada da Lista A
    }
    for (p = ListaSeparada; p != NULL && p->info != v; p = p->prox) // percorre a lista até encontrar o elemento V
        ;
    NoLista *nova = p->prox; // troca o elemento V pelo proximo elemento da lista
    p->prox = NULL;          // corta a lista
    ListaSeparada = nova;    // atribui o elemento V para a lista Separada
    return ListaSeparada;    // retorna a lista separada
}
