#ifndef LISTA_H
#define LISTA_H

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Registro {
    char nome[100];
    int idade;
    char rg[20];
    Data *entrada;
} Registro;

typedef struct Elista {
    Registro *dados;
    struct Elista *proximo;
} Elista;

typedef struct Lista {
    Elista *inicio;
    int qtde;
} Lista;

Lista* criar_lista();
void cadastrar_paciente(Lista *lista);
Elista* buscar_paciente(Lista *lista, char *rg);
void mostrar_lista(Lista *lista);
void atualizar_paciente(Lista *lista, char *rg);
void remover_paciente(Lista *lista, char *rg);
void liberar_lista(Lista *lista);

#endif