/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 02/11/2026
Objetivo    : 
Dificuldade : Entender arovere binária
Uso de IA   : Me ajudou a entender e resolver o problema
-------------------------------------------------------------------------- */

#include <stdio.h>

int valor[505], esq[505], dir[505];

int main(void) {
    int c;
    scanf("%d", &c);

    for (int caso = 1; caso <= c; caso++) {
        int n, total = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);

            valor[total] = v;
            esq[total] = dir[total] = -1;

            if (total > 0) {               /* desce a partir da raiz (nó 0) */
                int atual = 0;
                while (1) {
                    if (v < valor[atual]) {
                        if (esq[atual] == -1) { esq[atual] = total; break; }
                        atual = esq[atual];
                    } else {
                        if (dir[atual] == -1) { dir[atual] = total; break; }
                        atual = dir[atual];
                    }
                }
            }
            total++;
        }

        /* percurso por nível (BFS) com fila em vetor */
        int fila[505], ini = 0, fim = 0;
        fila[fim++] = 0;

        printf("Case %d:\n", caso);
        while (ini < fim) {
            int no = fila[ini++];

            if (no != 0) printf(" ");     /* espaço só entre elementos */
            printf("%d", valor[no]);

            if (esq[no] != -1) fila[fim++] = esq[no];
            if (dir[no] != -1) fila[fim++] = dir[no];
        }
        printf("\n\n");                    /* linha em branco após cada caso */
    }

    return 0;
}