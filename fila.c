#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

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

void menu_atendimento(Lista *lista, Fila *fila, Pilha *pilha) {
    int opcao;
    char rg[20];
    Elista *paciente;
    Operacao op;

    do {
        printf("\n--- Menu Atendimento Regular ---\n");
        printf("1. Enfileirar paciente\n");
        printf("2. Desenfileirar paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Voltar ao menu principal\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("RG do paciente para enfileirar: ");
                scanf("%s", rg);
                paciente = buscar_paciente(lista, rg);
                if (paciente != NULL) {
                    enfileirar(fila, paciente->dados);
                    printf("Paciente enfileirado com sucesso.\n");
                    strcpy(op.tipo, "enfileirar");
                    strcpy(op.nome, paciente->dados->nome);
                    empilhar(pilha, op);
                } else {
                    printf("Paciente não encontrado.\n");
                }
                break;
            case 2:
                if (fila->head != NULL) {
                    printf("Paciente %s desenfileirado.\n", fila->head->dados->nome);
                    strcpy(op.tipo, "desenfileirar");
                    strcpy(op.nome, fila->head->dados->nome);
                    empilhar(pilha, op);
                    desenfileirar(fila);
                } else {
                    printf("Fila vazia.\n");
                }
                break;
            case 3:
                mostrar_fila(fila);
                break;
        }
    } while (opcao != 0);
}