/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 23/09/2026
Objetivo    : Fazer um jogo de sudoku em que checa as linhas colunas e blocos 3x3 usando alocação dinâmica
Dificuldade : Saber como checar os blocos 3x3 e implementar alocação dinâmica
Uso de IA   : Usei para checar os blocos 3x3 e implementar alocação dinâmica
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int valida(int **m) {
    int i, j, r, c;

    /* linhas e colunas */
    for (i = 0; i < 9; i++) {
        int linha[10] = {0}, coluna[10] = {0};
        for (j = 0; j < 9; j++) {
            int a = m[i][j], b = m[j][i];
            if (a < 1 || a > 9 || linha[a]++)  return 0;
            if (b < 1 || b > 9 || coluna[b]++) return 0;
        }
    }

    /* regiões 3x3 */
    for (r = 0; r < 9; r += 3) {
        for (c = 0; c < 9; c += 3) {
            int visto[10] = {0};
            for (i = r; i < r + 3; i++)
                for (j = c; j < c + 3; j++)
                    if (visto[m[i][j]]++) return 0;
        }
    }

    return 1;
}

int main() {
    int n, k, i, j;

    /* aloca a matriz 9x9: um vetor de ponteiros, cada um apontando para uma linha */
    int **m = (int **) malloc(9 * sizeof(int *));
    if (m == NULL) return 1;
    for (i = 0; i < 9; i++) {
        m[i] = (int *) malloc(9 * sizeof(int));
        if (m[i] == NULL) return 1;
    }

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                scanf("%d", &m[i][j]);

        printf("Instancia %d\n%s\n\n", k, valida(m) ? "SIM" : "NAO");
    }

    /* libera primeiro as linhas, depois o vetor de ponteiros */
    for (i = 0; i < 9; i++)
        free(m[i]);
    free(m);

    return 0;
}