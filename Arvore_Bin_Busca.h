//
// Created by gabri on 25/03/2019.
//

#ifndef ARVORE_BINARIA_BUSCA_ARVORE_BIN_BUSCA_H
#define ARVORE_BINARIA_BUSCA_ARVORE_BIN_BUSCA_H

#endif //ARVORE_BINARIA_BUSCA_ARVORE_BIN_BUSCA_H

typedef struct no {
    char infor;
    struct no *esq;
    struct no *dir;
} Nodo;

typedef struct arv_bin {
    struct no *raiz;
} Arv_bin;

Arv_bin *arv_cria(Nodo *raiz);

Nodo *arv_cria_no(char infor, Nodo *esq, Nodo *dir);

void arv_libera(Arv_bin *raiz);

void no_libera(Nodo *no);

void insere(Arv_bin *arv, char valor);

Nodo *insere_nodo(Nodo *raiz, char valor);

void arv_remove(Arv_bin *arv_bin, char valor);

Nodo *nodo_remove(Nodo *raiz, char valor);

void inprime_escolhendo_ordem(Arv_bin *arv);

void pre(Nodo *no);

void in(Nodo *no);

void pos(Nodo *no);

void imprime_arvore(Nodo *raiz, int n);

void aux_print(char caracter, int n);