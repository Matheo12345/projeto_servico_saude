#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "heap.h"
#include "arvore.h"
#include "pilha.h"

void menu_principal() {
    printf("\n=== MENU ===\n");
    printf("1. Cadastrar\n");
    printf("2. Atendimento regular\n");
    printf("3. Atendimento prioritario\n");
    printf("4. Pesquisar\n");
    printf("5. Desfazer\n");
    printf("6. Carregar/Salvar\n");
    printf("7. Sobre\n");
    printf("0. Sair\n");
}



int main() {
    Lista *lista = criar_lista();
    Fila *fila = criar_fila();
    Heap *heap = criar_heap();
    Arvore *arvore = criar_arvore();
    Pilha *pilha = criar_pilha();
    int opcao;
    do {
        menu_principal();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                menu_cadastro(lista);
                break;
            case 2:
                menu_atendimento(lista, fila, pilha);
                break;
            case 3: {
                menu_atendimento_prioritario(lista, heap);
                break;
            }
            case 4: {
                carregar_lista_na_arvore(lista, arvore);
                menu_pesquisa(arvore);
                break;
            }
            case 5:
                menu_desfazer(pilha);
                break;
            case 6: {
                int escolha;
                char nome_arquivo[100] = "pacientes.csv";
                printf("1. Carregar lista\n2. Salvar lista\nEscolha: ");
                scanf("%d", &escolha);
                if (escolha == 1) {
                    carregar_lista(lista, nome_arquivo);
                } else if (escolha == 2) {
                    salvar_lista(lista, nome_arquivo);
                } else {
                    printf("Opção inválida.\n");
                }
                break;
            }
        }
    } while(opcao != 0);

    liberar_lista(lista);
    liberar_fila(fila);
    free(heap);
    free(arvore);
    liberar_pilha(pilha);
    return 0;
}