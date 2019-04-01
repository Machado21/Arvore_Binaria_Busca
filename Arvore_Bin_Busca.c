//
// Created by gabri on 25/03/2019.
//

#include "Arvore_Bin_Busca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Arv_bin *arv_cria(Nodo *raiz) {
    Arv_bin *arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo *arv_cria_no(char infor, Nodo *esq, Nodo *dir) {
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->infor = infor;
    return nodo;
}

void arv_libera(Arv_bin *raiz) {
    if (raiz) {
        no_libera(raiz->raiz);
        free(raiz);
    }
}

void no_libera(Nodo *no) {
    if (no) {
        no_libera(no->esq);
        no_libera(no->dir);
        free(no);
    }
}

void insere(Arv_bin *arv, char valor) {
    arv->raiz = insere_nodo(arv->raiz, valor);
}

Nodo *insere_nodo(Nodo *raiz, char valor) {

    if (raiz == NULL) {
        raiz = arv_cria_no(valor, NULL, NULL);
    } else if (valor < raiz->infor) {
        raiz->esq = insere_nodo(raiz->esq, valor);
    } else {
        raiz->dir = insere_nodo(raiz->dir, valor);
    }
    return raiz;
}

void arv_remove(Arv_bin *arv_bin, char valor) {
    arv_bin->raiz = nodo_remove(arv_bin->raiz, valor);
}

Nodo *nodo_remove(Nodo *raiz, char valor) {
    if (raiz == NULL) return NULL;
    else if (valor < raiz->infor)
        raiz->esq = nodo_remove(raiz->esq, valor);
    else if (valor > raiz->infor)
        raiz->dir = nodo_remove(raiz->dir, valor);
    else {
        if (raiz->dir == NULL && raiz->esq == NULL) {
            free(raiz);
            raiz = NULL;
        } else if (raiz->esq == NULL) {
            Nodo *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        } else if (raiz->dir == NULL) {
            Nodo *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        } else {
            Nodo *aux = raiz->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            raiz->infor = aux->infor;
            aux->infor = valor;
            raiz->esq = nodo_remove(raiz->esq, valor);
        }
    }
    return raiz;
}

void inprime_escolhendo_ordem(Arv_bin *arv) {
    int ordem;
    do {
        printf("1 - Imprime PreOrden. \n2 - Imprime InOrdem. \n3 - Imprime PosOrdem.\n4 - Imprime em formato de Arvore\n");
        scanf("%d", &ordem);
        switch (ordem) {
            case 1 :
                pre(arv->raiz);
                break;
            case 2 :
                in(arv->raiz);
                break;
            case 3 :
                pos(arv->raiz);
                break;
            case 4:
                imprime_arvore(arv->raiz, 1);
                break;
            default:
                printf("Opcao invalida, Tente de 1 a 3 : ");
                break;
        }
    } while (ordem < 1 || ordem > 3);

}

void pre(Nodo *no) {
    if (no) {
        printf("%c ", no->infor);
        pre(no->esq);
        pre(no->dir);
    }
}

void in(Nodo *no) {
    if (no) {
        in(no->esq);
        printf("%c ", no->infor);
        in(no->dir);
    }
}

void pos(Nodo *no) {
    if (no) {
        pos(no->esq);
        pos(no->dir);
        printf("%c ", no->infor);
    }
}

void imprime_arvore(Nodo *raiz, int n) {
    if (raiz == NULL) {
        aux_print('x', n);
        return;
    }
    imprime_arvore(raiz->esq, n + 1);
    aux_print(raiz->infor, n);
    imprime_arvore(raiz->dir, n + 1);
}

void aux_print(char caracter, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("---");
    }
    printf("%c\n", caracter);
}