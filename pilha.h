#ifndef PILHA_H
#define PILHA_H

typedef struct operacao {
    char tipo[50]; // "enfileirar" ou "desenfileirar"
    char nome[100];
} Operacao;

typedef struct epilha {
    Operacao operacao;
    struct epilha *proximo;
} EPilha;

typedef struct {
    EPilha *topo;
} Pilha;

Pilha* criar_pilha();
void empilhar(Pilha *pilha, Operacao operacao);
int desempilhar(Pilha *pilha, Operacao *destino);
void mostrar_pilha(Pilha *pilha);
void liberar_pilha(Pilha *pilha);
void menu_desfazer(Pilha *pilha);

#endif