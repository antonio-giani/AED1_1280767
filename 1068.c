/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 31/09/2026
Objetivo    : ler expressões até o fim da entrada e imprime “correct” se os parênteses de cada uma estão balanceados ou “incorrect” se não estão.
Dificuldade : usar fgets pela primeira vez
Uso de IA   : Me ajudou no fgets
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(void) {
    char linha[1105];

    while (fgets(linha, sizeof linha, stdin) != NULL) {
        int abertos = 0, ok = 1;

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '(') {
                abertos++;
            } else if (linha[i] == ')') {
                if (abertos == 0) {
                    ok = 0;
                    break;
                }
                abertos--;
            }
        }

        if (ok && abertos == 0)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}