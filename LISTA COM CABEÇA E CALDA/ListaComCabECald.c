#include <stdlib.h>
#include <stdio.h>

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

typedef struct lista
{
    NoLista *cab;
    NoLista *cau;
} Lista;

/*Criação da lista*/
void criarlista(Lista *l)
{
    l->cab = (NoLista *)malloc(sizeof(NoLista));
    l->cau = (NoLista *)malloc(sizeof(NoLista));
    l->cab->prox = l->cau;
    l->cau->prox = NULL;
}

/*Verificar se a lista esta vazia*/
int EstaVazia(Lista *l)
{
    return (l->cab->prox == l->cau);
}

/*Inserir elemento sempre no incio da lista*/
void InsereNoInicio(Lista *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL) // Verifica se teve alocação de memoria
    {
        novo->info = v;            // Coloca o valor no novo nó
        novo->prox = l->cab->prox; // Coloca o novo nó na posição do primeiro nó
        l->cab->prox = novo;       // Coloca o novo nó como o primeiro nó
    }
    else
    {
        printf("ERRO : Memoria insuficiente");
    }
}

/*Inserir elemento sempre no final da lista*/
void InsereNoFim(Lista *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = l->cau;
        NoLista *p;
        for (p = l->cab->prox; p->prox != l->cau; p = p->prox)
            ;
        p->prox = novo;
    }
    else
    {
        printf("ERRO : Memoria insuficiente");
    }
}

/*Imprimir o conteudo da lista*/
void Imprimir(Lista *l)
{
    NoLista *p;
    if (!EstaVazia(l)) // Verifica se a lista está vazia
    {
        for (p = l->cab->prox; p != l->cau; p = p->prox) // Percorre a lista
        {
            printf("%d ", p->info); // Imprime o valor do nó
        }
        printf("\n");
    }
    else
    {
        printf("Lista vazia");
    }
}

/*Remover elemento da lista*/
void RemoverElemento(Lista *l, int v)
{
    NoLista *p, *ant = NULL;
    if (!EstaVazia(l))
    {                                                                    // Verifica se a lista está vazia
        for (p = l->cab->prox; p != l->cau && p->info != v; p = p->prox) // Percorre a lista
        {
            ant = p; // ant recebe o elemento anterior de P
        }
        if (p == l->cau) // Verifica se o elemento foi encontrado
        {
            printf("Elemento não encontrado");
        }
        else
        {
            ant->prox = p->prox; // Remove o elemento da lista, o anterior -> prox de P recebe o proximo de P
            free(p);             // Libera a memoria do elemento removido
        }
    }
}

/*Remover todos elementos da lista e liberar a memoria*/
void Liberar(Lista *l)
{
    NoLista *p;
    NoLista *temp;
    if (!EstaVazia(l)) // Verifica se a lista está vazia
    {
        for (p = l->cab->prox; p != l->cau; p = temp)
        {
            temp = p->prox;
            free(p);
        }
        l->cab->prox = l->cau = NULL;
        l->cau = 0;
    }
    else
    {
        printf("Lista vazia");
    }
}

Lista *separar(Lista *l, int v)
{
    NoLista *p;
    for (p = l->cab->prox; p != l->cau && p->info != v; p = p->prox)
        ;
    if (p == l->cau)
    {
        printf("Elemento não encontrado");
        return NULL;
    }
    else
    {
        Lista *nova = (Lista *)malloc(sizeof(Lista));
        ;
        criarlista(nova);
        nova->cab->prox = p->prox;
        NoLista *q;
        for (q = nova->cab; q->prox != l->cau && q->prox != NULL; q = q->prox)
            ;
        q->prox = nova->cau;
        p->prox = l->cau;
        return nova;
    }
}

int main()
{
    Lista lista;
    criarlista(&lista);
    InsereNoInicio(&lista, 3);
    InsereNoInicio(&lista, 2);
    InsereNoInicio(&lista, 1);
    InsereNoFim(&lista, 4);
    Imprimir(&lista);
    Imprimir(separar(&lista, 2));
}