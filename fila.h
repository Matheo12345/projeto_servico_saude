#ifndef FILA_H
#define FILA_H

#include "lista.h"
#include "pilha.h"

typedef struct EFila {
    Registro *dados;
    struct EFila *proximo;
} EFila;

typedef struct Fila {
    EFila *head;
    EFila *tail;
    int qtde;
} Fila;

Fila* criar_fila();
void enfileirar(Fila *fila, Registro *dados);
void desenfileirar(Fila *fila);
void mostrar_fila(Fila *fila);
void liberar_fila(Fila *fila);
void menu_atendimento(Lista *lista, Fila *fila, Pilha *pilha);
#endif