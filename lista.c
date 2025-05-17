    #include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista* criar_lista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtde = 0;
    return lista;
}

void cadastrar_paciente(Lista *lista) {
    Elista *novo = (Elista*)malloc(sizeof(Elista));
    novo->dados = (Registro*)malloc(sizeof(Registro));
    novo->dados->entrada = (Data*)malloc(sizeof(Data));

    printf("Nome: ");
    scanf("%99s", novo->dados->nome);
    printf("Idade: ");
    scanf("%d", &novo->dados->idade);
    printf("RG: ");
    scanf("%19s", novo->dados->rg);
    printf("Data (dd mm aaaa): ");
    scanf("%d %d %d", 
        &novo->dados->entrada->dia,
        &novo->dados->entrada->mes,
        &novo->dados->entrada->ano
    );

    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->qtde++;
}

Elista* buscar_paciente(Lista *lista, char *rg) {
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void mostrar_lista(Lista *lista) {
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s | RG: %s\n", atual->dados->nome, atual->dados->rg);
        atual = atual->proximo;
    }
}

void liberar_lista(Lista *lista) {
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        Elista *temp = atual;
        atual = atual->proximo;
        free(temp->dados->entrada);
        free(temp->dados);
        free(temp);
    }
    free(lista);
}