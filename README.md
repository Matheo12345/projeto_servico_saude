# Projeto Serviço de Saúde

## Descrição

Este projeto é uma aplicação de gerenciamento de pacientes para um serviço de saúde, desenvolvida como trabalho da disciplina de Estrutura de Dados. O sistema permite o cadastro, consulta, atualização, remoção e atendimento de pacientes, utilizando diferentes estruturas de dados (lista, fila, pilha, heap e árvore binária de busca) para organizar e manipular as informações.

## Funcionalidades

- **Cadastro de Pacientes:** Adição, consulta, atualização e remoção de pacientes.
- **Atendimento Regular:** Gerenciamento de fila de atendimento comum.
- **Atendimento Prioritário:** Gerenciamento de fila prioritária utilizando heap, priorizando pacientes mais velhos.
- **Desfazer Operações:** Possibilidade de desfazer operações de enfileiramento e desenfileiramento usando pilha.
- **Pesquisa:** Visualização dos pacientes cadastrados em ordem de ano, mês, dia de entrada ou idade, utilizando árvore binária.
- **Persistência:** Carregamento e salvamento dos dados dos pacientes em arquivo CSV.

## Estruturas de Dados Utilizadas

- **Lista Encadeada:** Armazena todos os pacientes cadastrados.
- **Fila:** Gerencia a ordem de atendimento regular.
- **Heap:** Implementa a fila de prioridade para atendimento de pacientes mais velhos.
- **Pilha:** Permite desfazer operações de atendimento.
- **Árvore Binária de Busca:** Permite pesquisas e ordenações flexíveis dos pacientes.

## Arquivos Principais

- [`main.c`](main.c): Função principal e menu do sistema.
- [`lista.c`](lista.c) / [`lista.h`](lista.h): Implementação da lista de pacientes.
- [`fila.c`](fila.c) / [`fila.h`](fila.h): Implementação da fila de atendimento regular.
- [`heap.c`](heap.c) / [`heap.h`](heap.h): Implementação do heap para atendimento prioritário.
- [`pilha.c`](pilha.c) / [`pilha.h`](pilha.h): Implementação da pilha para desfazer operações.
- [`arvore.c`](arvore.c) / [`arvore.h`](arvore.h): Implementação da árvore binária para pesquisa e ordenação.
- [`pacientes.csv`](pacientes.csv): Arquivo de dados dos pacientes.

## Como Executar

1. Compile todos os arquivos `.c` juntos:
   ```sh
   gcc main.c lista.c fila.c heap.c pilha.c arvore.c -o servico_saude
   ```

## Autores

1. Matheo Campanelli de Aquino Esteves 
2. Edson Pedreira de Oliveira Junior
