#ifndef HEAP_H
#define HEAP_H

#include "lista.h"

#define MAX_HEAP 20

typedef struct Heap {
    Registro *dados[MAX_HEAP];
    int qtde;
} Heap;

Heap* criar_heap();
void inserir_heap(Heap *heap, Registro *dados);
void heapify_up(Heap *heap, int index);
Registro* remover_heap(Heap *heap);
void mostrar_heap(Heap *heap);

#endif