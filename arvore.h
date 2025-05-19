typedef struct no {
    Registro *dados;
    struct no *esq;
    struct no *dir;
} No;

typedef struct {
    No *raiz;
} Arvore;

Arvore *criar_arvore();
No *inserir_no(No *raiz, Registro *dados);
void inserir_arvore(Arvore *arvore, Registro *dados);
void em_ordem_ano(No *raiz);
void em_ordem_mes(No *raiz);
void em_ordem_dia(No *raiz);
void em_ordem_idade(No *raiz);
void menu_pesquisa(Arvore *arvore);
void carregar_lista_na_arvore(Lista *lista, Arvore *arvore);
int existe_paciente_na_arvore(No *raiz, char *rg);