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

//Funcao para inserir o elemento em uma max. heap
bool inserir(Heap *heap, int pri) {
    if (cheia(heap)) {
        return false;
    }
    heap->tam++;
    int k = heap->tam-1;
    heap->Prioridades[k].prioridade = pri;
    while(k != 0 && heap->Prioridades[pai(k)].prioridade < heap->Prioridades[k].prioridade) {
        swap(&(heap->Prioridades[pai(k)]), &(heap->Prioridades[k]));
        k = pai(k);
    }
    return true;
}

//Funcao para manter a regra do heap
void reorganizarMax(Heap *heap, int n){
    int tam = heap->tam;
    int e = filhoEsq(n);
    int r = filhoDir(n);
    int maior = n;
    if (e < tam && heap->Prioridades[e].prioridade > heap->Prioridades[n].prioridade) {
        maior = e;
    }
    if (r < tam && heap->Prioridades[r].prioridade > heap->Prioridades[maior].prioridade) {
        maior = r;
    }
    if (maior != n) {
        swap(&(heap->Prioridades[n]), &(heap->Prioridades[maior]));
        reorganizarMax(heap, maior);
    }
}

//Funcao para remover o elemento de uma max. heap
bool removerMax(Heap *heap) {
    if (heap->tam <= 0){
        return false;
    }
    if (heap->tam == 1){
        heap->tam--;
        return true;
    }

    int raiz =  heap->Prioridades[0].prioridade;
    heap->Prioridades[0] = heap->Prioridades[heap->tam-1];
    heap->tam--;
    reorganizarMax(heap, 0);
    return true;
}

//Funcao para imprimir o heap
void imprimir(Heap *heap) {
    for (int i = 0; i < heap->tam; i++){
        printf("Pos: %d Valor: %d\n", i, heap->Prioridades[i].prioridade);
    }
}


void main() {

    Heap *heap = criarHeap();
    inserir(heap, 3);
    inserir(heap, 4);
    inserir(heap, 7);
    inserir(heap, 1);
    inserir(heap, 9);
    inserir(heap, 11);
    inserir(heap, 6);
    inserir(heap, 5);
    removerMax(heap);
    imprimir(heap);
}
