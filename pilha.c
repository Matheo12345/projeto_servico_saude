pilha.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

Pilha* criar_pilha() {
    Pilha p = (Pilha) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha *pilha, Operacao operacao) {
    EPilha novo = (EPilha) malloc(sizeof(EPilha));
    novo->operacao = operacao;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(Pilha *pilha, Operacao *destino) {
    if (pilha->topo == NULL) return 0;
    EPilha *remover = pilha->topo;
    *destino = remover->operacao;
    pilha->topo = remover->proximo;
    free(remover);
    return 1;
}

void mostrar_pilha(Pilha *pilha) {
    EPilha *atual = pilha->topo;
    printf("\n--- Operações realizadas na fila ---\n");
    while (atual != NULL) {
        printf("%s: %s\n", atual->operacao.tipo, atual->operacao.nome);
        atual = atual->proximo;
    }
}

void liberar_pilha(Pilha *pilha) {
    Operacao temp;
    while (desempilhar(pilha, &temp));
    free(pilha);
}

void menu_desfazer(Pilha *pilha) {
    int confirmacao;
    Operacao ultima;
    if (!desempilhar(pilha, &ultima)) {
        printf("Nenhuma operação para desfazer.\n");
        return;
    }

    printf("Deseja desfazer a operação: %s (%s)? (1 = Sim / 0 = Não): ", ultima.tipo, ultima.nome);
    scanf("%d", &confirmacao);
    if (confirmacao == 1) {
        printf("Operação desfeita: %s\n", ultima.tipo);
        // Aqui você poderia adicionar lógica adicional se quisesse realmente reverter na fila
    } else {
        empilhar(pilha, ultima);
        printf("Operação mantida.\n");
    }
}