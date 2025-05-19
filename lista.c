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
        printf("Nome: %s | RG: %s | Idade: %d | Data de entrada: %02d/%02d/%04d\n", 
            atual->dados->nome, 
            atual->dados->rg, 
            atual->dados->idade, 
            atual->dados->entrada->dia, 
            atual->dados->entrada->mes, 
            atual->dados->entrada->ano
        );
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

void atualizar_paciente(Lista *lista, char *rg) {
    Elista *paciente = buscar_paciente(lista, rg);
    if (paciente != NULL) {
        printf("Novo nome: ");
        scanf("%99s", paciente->dados->nome);
        printf("Nova idade: ");
        scanf("%d", &paciente->dados->idade);
        printf("Nova data (dd mm aaaa): ");
        scanf("%d %d %d",
            &paciente->dados->entrada->dia,
            &paciente->dados->entrada->mes,
            &paciente->dados->entrada->ano
        );
        printf("Paciente atualizado com sucesso.\n");
    } else {
        printf("Paciente não encontrado.\n");
    }
}

void remover_paciente(Lista *lista, char *rg) {
    Elista *anterior = NULL;
    Elista *paciente = lista->inicio;
    while (paciente != NULL && strcmp(paciente->dados->rg, rg) != 0) {
        anterior = paciente;
        paciente = paciente->proximo;
    }
    if (paciente == NULL) {
        printf("Paciente não encontrado.\n");
    } else {
        if (anterior == NULL) {
            lista->inicio = paciente->proximo;
        } else {
            anterior->proximo = paciente->proximo;
        }
        free(paciente->dados->entrada);
        free(paciente->dados);
        free(paciente);
        lista->qtde--;
        printf("Paciente removido com sucesso.\n");
    }
}

void menu_cadastro(Lista *lista) {
    int opcao;
    char rg[20];
    Elista *paciente;

    do {
        printf("\n--- Menu Cadastro ---\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Consultar paciente por RG\n");
        printf("3. Mostrar lista completa\n");
        printf("4. Atualizar dados de paciente\n");
        printf("5. Remover paciente\n");
        printf("0. Voltar ao menu principal\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_paciente(lista);
                break;
            case 2:
                printf("RG: ");
                scanf("%s", rg);
                paciente = buscar_paciente(lista, rg);
                if (paciente != NULL)
                    printf("Paciente encontrado: %s\n", paciente->dados->nome);
                else
                    printf("Paciente não encontrado.\n");
                break;
            case 3:
                mostrar_lista(lista);
                break;
            case 4:
                printf("RG do paciente para atualizar: ");
                scanf("%s", rg);
                atualizar_paciente(lista, rg);
                break;
            case 5:
                printf("RG do paciente para remover: ");
                scanf("%s", rg);
                remover_paciente(lista, rg);
                break;
        }
    } while (opcao != 0);
}

void salvar_lista(Lista *lista, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    Elista *atual = lista->inicio;
    while (atual) {
        fprintf(arquivo, "%s;%d;%s;%d;%d;%d\n",
                atual->dados->nome,
                atual->dados->idade,
                atual->dados->rg,
                atual->dados->entrada->dia,
                atual->dados->entrada->mes,
                atual->dados->entrada->ano);
        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Pacientes salvos com sucesso em '%s'.\n", nome_arquivo);
}

void carregar_lista(Lista *lista, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo '%s' para leitura.\n", nome_arquivo);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Registro *r = (Registro *) malloc(sizeof(Registro));
        r->entrada = (Data *) malloc(sizeof(Data));
        sscanf(linha, "%[^;];%d;%[^;];%d;%d;%d",
               r->nome, &r->idade, r->rg,
               &r->entrada->dia, &r->entrada->mes, &r->entrada->ano);

        Elista *novo = (Elista *) malloc(sizeof(Elista));
        novo->dados = r;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->qtde++;
    }

    fclose(arquivo);
    printf("Pacientes carregados com sucesso de '%s'.\n", nome_arquivo);
}