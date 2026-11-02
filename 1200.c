/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 31/10/2026
Objetivo    : 
Dificuldade : Entender como fazer
Uso de IA   : Me ajudou a entender e resolver o problema
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq, *dir;
} No;

int primeiro;

No *inserir(No *raiz, char v) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->valor = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else
        raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

void imprimir(char v) {
    if (!primeiro) printf(" ");   /* espaço só entre elementos */
    printf("%c", v);
    primeiro = 0;
}

void infixa(No *raiz) {
    if (raiz == NULL) return;
    infixa(raiz->esq);
    imprimir(raiz->valor);
    infixa(raiz->dir);
}

void prefixa(No *raiz) {
    if (raiz == NULL) return;
    imprimir(raiz->valor);
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

void posfixa(No *raiz) {
    if (raiz == NULL) return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    imprimir(raiz->valor);
}

int existe(No *raiz, char v) {
    while (raiz != NULL) {
        if (v == raiz->valor) return 1;
        raiz = (v < raiz->valor) ? raiz->esq : raiz->dir;
    }
    return 0;
}

int main(void) {
    No *raiz = NULL;
    char cmd[20], c;

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &c);
            raiz = inserir(raiz, c);
        } else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &c);
            if (existe(raiz, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        } else {
            primeiro = 1;
            if (strcmp(cmd, "INFIXA") == 0)
                infixa(raiz);
            else if (strcmp(cmd, "PREFIXA") == 0)
                prefixa(raiz);
            else
                posfixa(raiz);
            printf("\n");
        }
    }

    return 0;
}