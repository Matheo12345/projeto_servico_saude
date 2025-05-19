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
#ifndef MAX_HEAP
#define MAX_HEAP 20
#endif

// Função menu de atendimento prioritário
void menu_atendimento_prioritario(Lista *lista, Heap *heap) {
    int opcao;
    char rg[20];
    Elista *paciente;
    Registro *removido;

    do {
        printf("\n--- Menu Atendimento Prioritário ---\n");
        printf("1. Enfileirar paciente prioritário\n");
        printf("2. Desenfileirar paciente prioritário\n");
        printf("3. Mostrar heap de prioridade\n");
        printf("0. Voltar ao menu principal\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (heap->qtde >= MAX_HEAP) {
                    printf("Capacidade máxima de atendimentos atingida (20 pacientes).\n");
                    break;
                }
                printf("RG do paciente para enfileirar: ");
                scanf("%s", rg);
                paciente = buscar_paciente(lista, rg);
                if (paciente != NULL) {
                    inserir_heap(heap, paciente->dados);
                    printf("Paciente inserido na fila prioritária com sucesso.\n");
                } else {
                    printf("Paciente não encontrado.\n");
                }
                break;
            case 2:
                removido = remover_heap(heap);
                if (removido != NULL) {
                    printf("Paciente %s (idade %d) removido da fila prioritária.\n", removido->nome, removido->idade);
                } else {
                    printf("Heap vazio.\n");
                }
                break;
            case 3:
                mostrar_heap(heap);
                break;
        }
    } while (opcao != 0);
}