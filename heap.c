#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

Heap* criar_heap() {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->qtde = 0;
    return heap;
}

void inserir_heap(Heap *heap, Registro *dados) {
    if (heap->qtde >= MAX_HEAP) {
        printf("Heap cheio!\n");
        return;
    }
    heap->dados[heap->qtde] = dados;
    heapify_up(heap, heap->qtde);
    heap->qtde++;
}

void heapify_up(Heap *heap, int index) {
    while (index > 0 && heap->dados[index]->idade > heap->dados[(index-1)/2]->idade) {
        Registro *temp = heap->dados[index];
        heap->dados[index] = heap->dados[(index-1)/2];
        heap->dados[(index-1)/2] = temp;
        index = (index-1)/2;
    }
}

Registro* remover_heap(Heap *heap) {
    if (heap->qtde == 0) return NULL;
    
    Registro *removido = heap->dados[0];
    heap->qtde--;
    heap->dados[0] = heap->dados[heap->qtde];
    // Implementar heapify_down aqui
    return removido;
}

void mostrar_heap(Heap *heap) {
    for (int i = 0; i < heap->qtde; i++) {
        printf("%s (Idade: %d)\n", heap->dados[i]->nome, heap->dados[i]->idade);
    }
}