/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1340
Data        : 2/10/2026
Objetivo    : Descobrir se a sequência de operações corresponde a uma pilha, uma fila ou uma fila de prioridade.
Dificuldade : A primeira solução confiava que x era no máximo 100, mas os testes tinham valores maiores, e o programa escrevia fora do vetor.
Uso de IA   : Para estruturar o exercicio inteiro.
-------------------------------------------------------------------------- */


#include <stdio.h>

int main(void) {
    int n;

    while (scanf("%d", &n) == 1) {
        int pilha[1005], topo = 0;
        int fila[1005], ini = 0, fim = 0;
        int prio[1005], tamPrio = 0;
        int ehPilha = 1, ehFila = 1, ehPrio = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                pilha[topo++] = x;
                fila[fim++] = x;
                prio[tamPrio++] = x;
            } else {
                if (topo == 0) {
                    ehPilha = ehFila = ehPrio = 0;
                    continue;
                }

                if (pilha[--topo] != x) ehPilha = 0;
                if (fila[ini++] != x) ehFila = 0;

                int pos = 0;
                for (int j = 1; j < tamPrio; j++)
                    if (prio[j] > prio[pos]) pos = j;
                if (prio[pos] != x) ehPrio = 0;
                prio[pos] = prio[--tamPrio];
            }
        }

        int qtd = ehPilha + ehFila + ehPrio;

        if (qtd == 0)
            printf("impossible\n");
        else if (qtd > 1)
            printf("not sure\n");
        else if (ehPilha)
            printf("stack\n");
        else if (ehFila)
            printf("queue\n");
        else
            printf("priority queue\n");
    }

    return 0;
}