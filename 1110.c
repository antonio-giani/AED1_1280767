/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/09/2026
Objetivo    : 
Dificuldade : Saber como checar os blocos 3x3
Uso de IA   : Usei para checar os blocos 3x3
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

/* Nó da lista encadeada */
typedef struct No {
    int valor;
    struct No *prox;
} No;

/* Pilha de cartas: topo = inicio, base = fim */
typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void inicializar(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

/* Insere uma carta na base (fim da lista) */
void inserirFim(Lista *l, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (l->fim == NULL)
        l->inicio = novo;
    else
        l->fim->prox = novo;
    l->fim = novo;
    l->tamanho++;
}

/* Remove a carta do topo (início da lista) e devolve seu valor */
int removerInicio(Lista *l) {
    No *aux = l->inicio;
    int valor = aux->valor;
    l->inicio = aux->prox;
    if (l->inicio == NULL)
        l->fim = NULL;
    free(aux);
    l->tamanho--;
    return valor;
}

/* Move a carta do topo para a base, reaproveitando o próprio nó */
void moverTopoParaBase(Lista *l) {
    if (l->inicio == l->fim) return;   /* só uma carta: nada a fazer */
    No *aux = l->inicio;
    l->inicio = aux->prox;
    aux->prox = NULL;
    l->fim->prox = aux;
    l->fim = aux;
}

void liberar(Lista *l) {
    while (l->inicio != NULL)
        removerInicio(l);
}

int main() {
    int n, i;

    while (scanf("%d", &n) == 1 && n != 0) {
        Lista pilha;
        inicializar(&pilha);

        for (i = 1; i <= n; i++)
            inserirFim(&pilha, i);

        printf("Discarded cards:");
        int primeira = 1;
        while (pilha.tamanho >= 2) {
            int descartada = removerInicio(&pilha);
            if (primeira) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }
            moverTopoParaBase(&pilha);
        }
        printf("\n");

        printf("Remaining card: %d\n", pilha.inicio->valor);

        liberar(&pilha);
    }

    return 0;
}