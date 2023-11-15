#include <stdio.h>
#include <stdlib.h>
#include "function.h"


void Tela(){
    printf("\n\t\t\t\t\tATENÇÃO:  MATENHA CAPS LOCK DESATIVADA\n\n");
    for(int i = 0; i < largura; i++){
        printf("░");
    }
    printf("\n");

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){

            if(j == 0){
                printf("░");
            }
            else if (j == largura - 1)
            {
                printf("░");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }

    for(int i = 0; i < largura; i++){
        printf("░");
    }
    printf("\n");
}

void EscreverArquivo(FILE* arquivo, pontuacao players){  
    fprintf(arquivo, "Player 1: %d\n", players.player1);
    fprintf(arquivo, "Player 2: %d\n", players.player2);
}

void PrintPontos(pontuacao pontos){
    printf("\n\t titulo: %d\n", pontos.player1);
    printf("\tAutor: %d\n", pontos.player2);
    puts("==================================");
}