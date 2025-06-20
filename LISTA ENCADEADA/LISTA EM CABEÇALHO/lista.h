#ifndef LISTA_H
#define LISTA_H

typedef struct nolista
{
    int info;
    struct nolista *prox;
} NoLista;

void CriarLista(NoLista **l);
int EstaVazia(NoLista **l);
void InsereElementoInicio(NoLista **l, int v);
void InsereElementoFim(NoLista **l, int v);
void InsereElementoMeio(NoLista **l, int v, int ant);
void Imprimir(NoLista **l);
void InsereOrdenado(NoLista **l, int v);
void LiberarLista(NoLista **l);
void RemoverElemento(NoLista **l, int v);
NoLista *buscar(NoLista **l, int v);
NoLista *ultimo(NoLista **l);
int QuantidadeElemento(NoLista **l);
int maiores(NoLista **l, int v);
NoLista *concatena(NoLista **l1, NoLista **l2);
NoLista *separa(NoLista **l, int v);

#endif