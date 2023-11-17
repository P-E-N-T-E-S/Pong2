#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int bolaX = 5;
int bolaY = 5;
int velocidadeX = 1;
int velocidadeY = 1;
int seg = 30;
int mim = 1;
int temp = 0;
int barraEsquerda;
int barraDireita;


void Tela() {
    LimparTela();

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (j == 0 || j == largura - 1) {
                printf("░");
            } else if ((i == 0 || i == altura - 1) && (j > 0 && j < largura - 1)) {
                printf("░");
            } else if (j == 2 && (i >= barraEsquerda - 2 && i <= barraEsquerda + 2)) {
                printf("█");
            } else if (j == largura - 3 && (i >= barraDireita - 2 && i <= barraDireita + 2)) {
                printf("█");
            } else if (i == bolaY && j == bolaX) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    temp++;

    if (temp % 10 == 0) {
        seg--;
    }

    if (mim == 0 && seg == 0) {
        printf("O tempo acabou !");
        exit(1);
    }
    printf("\n\n%02d:%02d\n\n", mim, seg);

    if (seg == 0) {
        mim--;
        seg = seg + 60;
    }
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

void AtualizarBola() {
    bolaX += velocidadeX;
    bolaY += velocidadeY;

    if (bolaX <= 0) {
        velocidadeX = -velocidadeX;
    }

    if (bolaX >= largura - 1) {
        velocidadeX = -velocidadeX;
    }

    if (bolaY <= 0) {
        velocidadeY = -velocidadeY;
    }

    if (bolaY >= altura - 1) {
        velocidadeY = -velocidadeY;
    }

    if (bolaX == 2 && (bolaY >= barraEsquerda - 2 && bolaY <= barraEsquerda + 2)) {
        velocidadeX = -velocidadeX;
    }

    if (bolaX == largura - 3 && (bolaY >= barraDireita - 2 && bolaY <= barraDireita + 2)) {
        velocidadeX = -velocidadeX;
    }
}

void LimparTela() {
    system("clear");
}