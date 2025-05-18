#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "heap.h"

void menu_principal() {
    printf("\n=== MENU ===\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Atendimento regular\n");
    printf("3. Atendimento prioritario\n");
    printf("4. Pesquisar\n");
    printf("5. Desfazer\n");
    printf("6. Carregar/Salvar\n");
    printf("7. Sobre\n");
    printf("0. Sair\n");
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

int main() {
    Lista *lista = criar_lista();
    Fila *fila = criar_fila();
    Heap *heap = criar_heap();

    int opcao;
    do {
        menu_principal();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                menu_cadastro(lista);
                break;
            case 2: {
                char rg[20];
                printf("RG do paciente: ");
                scanf("%19s", rg);
                Elista *paciente = buscar_paciente(lista, rg);
                if (paciente != NULL) {
                    enfileirar(fila, paciente->dados);
                } else {
                    printf("Paciente nao encontrado!\n");
                }
                break;
            }
            case 3: {
                // Implementar atendimento prioritario
                break;
            }
            // Implementar outros casos...
        }
    } while(opcao != 0);

    liberar_lista(lista);
    liberar_fila(fila);
    free(heap);
    return 0;
}