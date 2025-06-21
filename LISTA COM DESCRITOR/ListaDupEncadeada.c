#include <stdlib.h>
#include <stdio.h>

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

typedef struct descritor
{
    NoLista *prim;
    NoLista *ult;
    int n;
} Descritor;

void CriarLista(Descritor *l)
{
    l->prim = l->ult = NULL;
    l->n = 0;
}

int EstaVazia(Descritor *l)
{
    return (l->prim == NULL);
}

/*Função para inserir elementos sempre no inicio*/
void InsereElementoInicio(Descritor *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista)); // Aloca memoria para o novo elemento
    if (novo != NULL)                                   // Verifica se a memoria foi alocada com sucesso
    {
        novo->info = v;       // Coloca o valor no novo elemento
        novo->prox = l->prim; // Coloca o novo elemento no inicio da lista
        l->prim = novo;       // Atualiza o primeiro elemento da lista
        if (l->n == 0)        // Verifica se a lista estava vazia
        {
            l->ult = novo; // Atualiza o ultimo elemento da lista
        }
        l->n++; // Incrementa o tamanho da lista
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

void InsereElementoFim(Descritor *l, int v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = v;
        novo->prox = NULL;
        if (!EstaVazia(l)) // Verifica se a lista não esta vazia
        {
            l->ult->prox = novo; // prox do ultimo elemento vai receber o conteudo do novo
            l->ult = novo;       // ultimo elemento se torna o novo
        }
        else // se a lista estiver vazia
        {
            l->ult = novo;  // o ultimo se torna o novo
            l->prim = novo; // o primeiro se torna o novo
        }
        l->n++;
    }
    else
    {
        printf("Erro ao alocar memoria\n");
    }
}

/*Exibir a lista*/
void ImprimirElemento(Descritor *l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = l->prim; p != NULL; p = p->prox) // Percorre a lista
        {
            printf("%d ", p->info); // Imprime o conteudo do elemento
        }
    }
    else
    {
        printf("Lista vazia");
    }
}

/*Remover o elemento V da lista*/
void RemoverElemento(Descritor *l, int v)
{
    NoLista *p;
    NoLista *ant = NULL;                                      // Variavel que armazena o antecessor do elemento a ser removido
    for (p = l->prim; p != NULL && p->info != v; p = p->prox) // percorre a lista ate encontrar o elemento
    {
        ant = p; // armazena o elemento anterior
    }
    if (p == NULL)
    {
        printf("Elemento nao encontrado\n");
    }
    else
    {
        if (ant == NULL)
        {
            l->prim = p->prox;
            if (l->prim == NULL) // Lista com um elemento
            {
                l->ult = NULL;
            }
        }
        else
        {
            ant->prox = p->prox; // ant vai apontar para o proximo elemento de p
            if (ant->prox == NULL)
            {                 // se o proximo elemento for nulo que dizer que e o ultimo elemento da lista
                l->ult = ant; // o ant agora é o ultimo elemento
            }
        }
        free(p);
        l->n--;
    }
}

/*Buscar elemento V na lista*/
Descritor *BuscarElemento(Descritor *l, int v)
{
    NoLista *p;
    for (p = l->prim; p != NULL && p->info != v; p = p->prox) // percorre a lista ate encontrar o elemento
        ;
    if (p->info == v) // se o elemento foi encontrado
    {
        return p; // retorna o endereco do elemento
    }
    else
    {
        return NULL;
    }
}

/*Esvazia a lista*/
void LiberarLista(Descritor *l)
{
    NoLista *p;
    NoLista *temp;
    for (p = l->prim; p != NULL; p = temp) // percorre a lista ate esvaziar ela
    {
        temp = p->prox; // salva o proximo elemento
        free(p);        // libera o elemento
    }
    l->prim = l->ult = NULL; // lista vazia
    l->n = 0;                // quantidade de elementos = 0
}

/*Buscar ultimo elemtento da lista*/
Descritor *UltimoElemento(Descritor *l)
{
    NoLista *p;
    if (!EstaVazia(l))
    {
        for (p = l->prim; p->prox != NULL; p = p->prox) // percorre a lista ate encontrar o ultimo elemento
            ;
        return p; // retorna o endereco do ultimo elemento
    }
    else
    {
        return NULL;
    }
}

Descritor *QuantidadeDeElemento(Descritor *l)
{
    return l->n;
}

Descritor *separa(Descritor *l, int v)
{
    NoLista *p, *ant = NULL;
    Descritor *nova = NULL;                                   // cria uma nova lista
    for (p = l->prim; p != NULL && p->info != v; p = p->prox) // percorre a lista ate encontrar o elemento
    {
        ant = p; // salva o endereco do elemento anterior
    }

    if (p == NULL) // se o elemento nao foi encontrado
    {
        nova->prim = nova->ult = NULL; // lista vazia
        nova->n = 0;                   // quantidade de elementos = 0
        return nova;                   // retorna a lista vazia
    }
    nova->prim = p->prox;                        // o primeiro elemento da nova lista rebebe o proximo do elemento que iremos cortar
    nova->ult = l->ult;                          // o ultimo elemento da nova lista rebebe o ultimo da lista original
    nova->n = 0;                                 // quantidade de elementos = 0
    NoLista *q;                                  // ponteiro auxiliar
    for (q = nova->prim; q != NULL; q = q->prox) // percorre a lista nova para contar a quantidade de elementos
    {
        nova->n++; // incrementa a quantidade de elementos
        if (q->prox == NULL)
        {
            nova->ult = q;
        }
    }

    p->prox = NULL;
    l->ult = p;
    l->n = nova->n;
    return nova;
}

void main()
{
    Descritor lista;
    NoLista *c;
    CriarLista(&lista);
    InsereElementoInicio(&lista, 1);
    InsereElementoInicio(&lista, 2);
    InsereElementoInicio(&lista, 3);
    InsereElementoFim(&lista, 4);
    InsereElementoFim(&lista, 5);
    ImprimirElemento(&lista);
    printf("\n");
    ImprimirElemento(separa(&lista, 4));
    printf("\nQuantidade de elementos: %d\n", QuantidadeDeElemento(&lista));
}