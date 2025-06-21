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
void CriarLista(Lista *l)
{
    l->cab = (NoLista *)malloc(sizeof(NoLista));
    l->cau = (NoLista *)malloc(sizeof(NoLista));
    l->cab->prox = l->cau;
    l->cau->prox = NULL;
}

/*Verificar se a lista esta vazia*/
int EstaVazia(Lista *l)
{
    if (l->cab->prox == l->cau)
    {
        return 1;
    }
    else
    {
        return NULL;
    }
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
    {                        // Verifica se teve alocação de memoria
        novo->prox = NULL;   // Coloca o novo nó como o último nó
        l->cau->info = v;    // Coloca cau receber o ultimo valor
        l->cau->prox = novo; // Coloca o novo nó como o último nó da lista
        l->cau = novo;       // Coloca o novo nó como o último nó da lista
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
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    NoLista *p, *ant = NULL;
    if (!EstaVazia(l))
    {
        for (p = l->cab->prox; p != l->cau && p->info != v; p = p->prox)
        {
            ant = p;
        }
        if (p != l->cau)
        {
            nova->cau = l->cau;
            nova->cab->prox = p->prox;
            p->prox = l->cau;
        }
        else
        {
            nova->cab = nova->cau = NULL;
        }
    }
    else
    {
        nova->cab = nova->cau = NULL;
    }
    return nova;
}

int main()
{
    Lista lista;
    CriarLista(&lista);
    InsereNoInicio(&lista, 3);
    InsereNoInicio(&lista, 2);
    InsereNoInicio(&lista, 1);
    InsereNoFim(&lista, 4);
    Imprimir(&lista);
    Imprimir(separar(&lista, 2));
}