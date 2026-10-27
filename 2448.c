/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 9/10/2026
Objetivo    : Resolver usando busca binaria
Dificuldade : Entender como usar busca binaria
Uso de IA   : Entender como usar busca binaria
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

#define MAX_N 45005

// Função de busca binária para encontrar o índice de uma casa no vetor
int buscaBinaria(int casas[], int n, int alvo) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (casas[meio] == alvo) {
            return meio;
        }
        if (casas[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int casas[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    long long tempo_total = 0;
    int pos_atual = 0; // O carteiro começa na primeira casa (índice 0)

    for (int i = 0; i < m; i++) {
        int encomenda;
        scanf("%d", &encomenda);

        // Encontra o índice da casa de destino usando busca binária
        int pos_destino = buscaBinaria(casas, n, encomenda);

        // Soma o tempo necessário (diferença entre os índices)
        tempo_total += abs(pos_destino - pos_atual);

        // Atualiza a posição atual do carteiro
        pos_atual = pos_destino;
    }

    printf("%lld\n", tempo_total);

    return 0;
}