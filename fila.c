#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* criar_fila() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->head = fila->tail = NULL;
    fila->qtde = 0;
    return fila;
}

void enfileirar(Fila *fila, Registro *dados) {
    EFila *novo = (EFila*)malloc(sizeof(EFila));
    novo->dados = dados;
    novo->proximo = NULL;

    if (fila->head == NULL) {
        fila->head = fila->tail = novo;
    } else {
        fila->tail->proximo = novo;
        fila->tail = novo;
    }
    fila->qtde++;
}

void desenfileirar(Fila *fila) {
    if (fila->head == NULL) return;
    
    EFila *temp = fila->head;
    fila->head = fila->head->proximo;
    free(temp);
    fila->qtde--;
}

void mostrar_fila(Fila *fila) {
    EFila *atual = fila->head;
    while (atual != NULL) {
        printf("Paciente: %s (RG: %s)\n", atual->dados->nome, atual->dados->rg);
        atual = atual->proximo;
    }
}

void liberar_fila(Fila *fila) {
    while (fila->head != NULL) {
        desenfileirar(fila);
    }
    free(fila);
}