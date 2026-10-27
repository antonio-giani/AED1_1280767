/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Antonio Callegher Gandini Giani
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 23/09/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos. Resolva usando alocação dinâmica
Dificuldade : Lembrar como faz alocação
Uso de IA   : Me ensinar o que cada parte do malloc faz
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, maior, posicao;
    int *v = (int *)malloc(100 * sizeof(int));

    if (v == NULL) return 1;

    for (i = 0; i < 100;  i++){
        scanf ("%d", v[i]);
    }

    maior = v[0];
    posicao = 0;
       for (i = 0; i < 100;  i++){
            if (v[i] > maior){
                maior = v[i];
                posicao = i;
            }
    }
    
    printf("%d\n%d\n", maior, posicao + 1); 

    free(v);
    return 0;
}


