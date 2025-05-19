#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "arvore.h"

Arvore *criar_arvore() {
    Arvore *a = (Arvore *) malloc(sizeof(Arvore));
    a->raiz = NULL;
    return a;
}

No *inserir_no(No *raiz, Registro *dados) {
    if (raiz == NULL) {
        No *novo = (No *) malloc(sizeof(No));
        novo->dados = dados;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (dados->entrada->ano < raiz->dados->entrada->ano)
        raiz->esq = inserir_no(raiz->esq, dados);
    else
        raiz->dir = inserir_no(raiz->dir, dados);
    return raiz;
}

void inserir_arvore(Arvore *arvore, Registro *dados) {
    arvore->raiz = inserir_no(arvore->raiz, dados);
}

void em_ordem_ano(No *raiz) {
    if (raiz != NULL) {
        em_ordem_ano(raiz->esq);
        printf("Paciente: %s | Ano: %d\n", raiz->dados->nome, raiz->dados->entrada->ano);
        em_ordem_ano(raiz->dir);
    }
}

// Outros critérios de ordenação
void em_ordem_mes(No *raiz) {
    if (raiz != NULL) {
        em_ordem_mes(raiz->esq);
        printf("Paciente: %s | Mês: %d\n", raiz->dados->nome, raiz->dados->entrada->mes);
        em_ordem_mes(raiz->dir);
    }
}

void em_ordem_dia(No *raiz) {
    if (raiz != NULL) {
        em_ordem_dia(raiz->esq);
        printf("Paciente: %s | Dia: %d\n", raiz->dados->nome, raiz->dados->entrada->dia);
        em_ordem_dia(raiz->dir);
    }
}

void em_ordem_idade(No *raiz) {
    if (raiz != NULL) {
        em_ordem_idade(raiz->esq);
        printf("Paciente: %s | Idade: %d\n", raiz->dados->nome, raiz->dados->idade);
        em_ordem_idade(raiz->dir);
    }
}

void menu_pesquisa(Arvore *arvore) {
    int opcao;
    do {
        printf("\n--- Menu Pesquisa ---\n");
        printf("1. Mostrar por ano\n");
        printf("2. Mostrar por mês\n");
        printf("3. Mostrar por dia\n");
        printf("4. Mostrar por idade\n");
        printf("0. Voltar ao menu principal\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: em_ordem_ano(arvore->raiz); break;
            case 2: em_ordem_mes(arvore->raiz); break;
            case 3: em_ordem_dia(arvore->raiz); break;
            case 4: em_ordem_idade(arvore->raiz); break;
        }
    } while (opcao != 0);
}

int existe_paciente_na_arvore(No *raiz, char *rg) {
    if (raiz == NULL) return 0;
    if (strcmp(raiz->dados->rg, rg) == 0) return 1;
    return existe_paciente_na_arvore(raiz->esq, rg) || existe_paciente_na_arvore(raiz->dir, rg);
}

void carregar_lista_na_arvore(Lista *lista, Arvore *arvore) {
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        if (!existe_paciente_na_arvore(arvore->raiz, atual->dados->rg)) {
            inserir_arvore(arvore, atual->dados);
        }
        atual = atual->proximo;
    }
}