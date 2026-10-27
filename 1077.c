/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : /10/2026
Objetivo    : Infixa e posfixa
Dificuldade : Aprender as duas maneiras de escrever uma expressão e transformar a leitura de uma expressão matemática em código
Uso de IA   : Correção e entender a lógica principal
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedencia(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0; 
}

void infixa_para_posfixa(const char *exp) {
    char pilha[305];
    int topo = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == '\n' || c == '\r') continue;

        if (isalnum(c)) {
            putchar(c);
        }
        else if (c == '(') {
            pilha[++topo] = c;
        }
        else if (c == ')') {
            while (topo >= 0 && pilha[topo] != '(') {
                putchar(pilha[topo--]);
            }
            if (topo >= 0 && pilha[topo] == '(') {
                topo--; 
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (topo >= 0 && precedencia(pilha[topo]) >= precedencia(c)) {
                putchar(pilha[topo--]);
            }
            pilha[++topo] = c;
        }
    }

    while (topo >= 0) {
        if (pilha[topo] != '(') {
            putchar(pilha[topo]);
        }
        topo--;
    }
    putchar('\n');
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char expressao[305];
    while (N--) {
        scanf("%s", expressao);
        infixa_para_posfixa(expressao);
    }

    return 0;
}