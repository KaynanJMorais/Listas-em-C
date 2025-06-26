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
        for (p = l->cab->prox; p != l->cau; p = temp) // Percorre a lista
        {
            temp = p->prox; // Temp recebe o proximo de P
            free(p); // Libera a memoria do elemento
        }
        l->cab->prox = l->cau = NULL; // Libera a memoria do cabeca e cauda
        l->cau = 0; // Define a cauda como 0
    }
    else
    {
        printf("Lista vazia");
    }
}

Lista separa(Lista *l, int v)
{
    NoLista *p;
    for (p = l->cab->prox; p->info != v && p->prox != l->cau; p = p->prox) // Percorre a lista
    {
    }
    if (p->info != v) // Verifica se o elemento foi encontrado
    {
        printf("ELEMENTO NAO ENCONTRADO\n");
    }
    else
    {
        NoLista *c; // Cria um novo elemento
        c = p->prox; // C recebe o proximo de P
        NoLista *b = c; // B recebe o elemento C
        for (; c->prox != l->cau; c = c->prox) // Percorre a lista
        { 
        }
        Lista nova; // Cria uma nova lista
        criarlista(&nova); // Cria uma nova lista
        nova.cab->prox = b; // A nova lista recebe o elemento B
        p->prox = l->cau; // O elemento P recebe a cauda da lista
        c->prox = nova.cau; // O elemento C recebe a cauda da nova lista
        return nova; // Retorna a nova lista
    }
}

Lista concatena(Lista *l1, Lista *l2)
{
    NoLista *p;
    Lista nova;
    if (EstaVazia(l1)) // Verifica se a lista 1 está vazia
    {
        nova.cab = l2->cab;  // A nova lista recebe a cabeca da lista 2
        nova.cau = l2->cau;  // A nova lista recebe a calda da lista 2
        return nova; // Retorna a nova lista
    }
    if (EstaVazia(l2))
    {
        nova.cab = l1->cab; // A nova lista recebe a cabeca da lista 1
        nova.cau = l2->cau; // A nova lista recebe a cauda da lista 2
        return nova; // Retorna a nova lista
    }
    nova.cab = l1->cab; // A nova lista recebe a cabeca da lista 1
    nova.cau = l2->cau; // A nova lista recebe a cauda da lista 2

    for (p = l1->cab->prox; p->prox != l1->cau; p = p->prox) // Percorre a lista 1
        ;
    p->prox = l2->cab->prox; // O elemento P recebe a cabeca da lista 2
    return nova; // Retorna a nova lista
}

int main()
{
    Lista a;
    Lista b;
    criarlista(&a);
    criarlista(&b);
    InsereNoInicio(&a, 3);
    InsereNoInicio(&a, 2);
    InsereNoInicio(&b, 1);
    InsereNoFim(&b, 4);
    Lista q = concatena(&a, &b);
    Imprimir(&q);
}