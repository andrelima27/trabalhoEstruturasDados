#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef int Prioridade;

typedef struct a {
    Prioridade prioridade;
} Item;

typedef struct estrutura {
    int tam; //quantidade de elementos que o heap possue
    int max; //quantidade maxima de elementos que o heap possue
    Item *Prioridades;
} Heap;

// Função para criar um heap 
Heap * criarHeap() {
    Heap *heap;
    heap = malloc(sizeof(Heap));
    heap -> Prioridades = malloc(MAX*sizeof(Item));
    heap->tam = 0;
    heap->max = MAX;
    return heap;
}

//Função para verificar se o heap esta vazio
bool vazia(Heap *heap) {
    return !heap->tam;
}

//Função para verificar se o heap esta cheio
bool cheia(Heap *heap) {
    return heap->max == heap->tam;
}

//Descobre o indice do elemento acima
int pai(int n) {
    return n/2;
}

//Descobre o indice do elemento a esquerda
int filhoEsq(int n) {
    return n * 2;
}

//Descobre o indice do elemento a direita
int filhoDir(int n) {
    return n * 2 + 1;
}

//Funcao para trocar os valores das referencias
void swap(Item *x, Item *y) {

    Item aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
