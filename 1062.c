/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 26/10/2026
Objetivo    : Resolver usando pilha 
Dificuldade : 
Uso de IA   : Ajudar a achar erros
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdbool.h>

#define MAX 1005

// Estrutura de Pilha para simular a estação de trem
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, int valor) {
    p->dados[++(p->topo)] = valor;
}

int topo(Pilha *p) {
    return p->dados[p->topo];
}

void desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        p->topo--;
    }
}

int main() {
    int n;

    // Processa cada bloco de testes até encontrar N = 0
    while (scanf("%d", &n) == 1 && n != 0) {
        while (1) {
            int desejado[MAX];

            // Lê o primeiro vagão da sequência
            scanf("%d", &desejado[0]);

            // Se o primeiro valor for 0, encerra o bloco atual
            if (desejado[0] == 0) {
                break;
            }

            // Lê os demais N - 1 vagões do arranjo desejado
            for (int i = 1; i < n; i++) {
                scanf("%d", &desejado[i]);
            }

            Pilha estacao;
            inicializar(&estacao);

            int idx_desejado = 0;

            // Tenta organizar os vagões que entram da direção A (de 1 a N)
            for (int vagao = 1; vagao <= n; vagao++) {
                empilhar(&estacao, vagao);

                // Enquanto o vagão no topo da estação for o esperado para sair na direção B
                while (!estaVazia(&estacao) && topo(&estacao) == desejado[idx_desejado]) {
                    desempilhar(&estacao);
                    idx_desejado++;
                }
            }

            // Se todos os N vagões saíram na ordem correta, é possível
            if (idx_desejado == n) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        // Linha em branco ao final de cada bloco
        printf("\n");
    }

    return 0;
}