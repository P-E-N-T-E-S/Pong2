#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <unistd.h>
#include <time.h>
#include "keyboard.h"

int barraEsquerda = 10;
int barraDireita = 10;


int main(){
    pontuacao pontos;
    int op;
    FILE *file;
    file = fopen("pontos.txt", "w");
    int jogando = 0;

    if(file == NULL){
        exit(1);
    }


    while(1){
        printf("O que você deseja fazer?\n");
        puts("\n1 - Jogar\n2 - Ajuda\n3 - Histórico\n4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op){
        case 1:
            jogando = 1;
            keyboardInit();
            while (jogando) {
                if (keyhit()) {
                    char keyPressed = readch();
                    if (keyPressed == 'w') {
                        if (barraEsquerda > 0) {
                            barraEsquerda--;
                            Tela();
                        }
                    }
                    if(keyPressed == 's'){
                        if(barraEsquerda < altura - 4){
                            barraEsquerda++;
                            Tela();
                        }
                    }
                    if (keyPressed == 'i')
                    {
                        if(barraDireita > 0){
                            barraDireita--;
                            Tela();
                        }
                    }
                    if (keyPressed == 'j')
                    {
                        if (barraDireita < altura -4)
                        {
                            barraDireita++;
                            Tela();
                        }
                    }
                }
                Tela();
                AtualizarBola();
                AtualizarSegundaBola();
                usleep(100000);
            }
            keyboardDestroy();
            break;
        case 2:
            system("clear");
            printf("\nControles:\n");
            printf("\nJogador 1:\n\nW - Cima\nS - Baixo\n");
            printf("\nJogador 2:\n\nI - Cima\nJ - Baixo\n");
            printf("\nEventos:\n");
            printf("\nA cada 30s um novo evento aparece, e eles são:\n");
            printf("\nBola dupla\nPontos duplos\nVelocidade Dobrada\n\n");
            break;

        case 3:
            system("clear");
            puts("\n\nPONTUAÇÃO");
            puts("==================================");
            fseek(file, 0, SEEK_SET);
            while (fread(&pontos, sizeof(pontuacao), 1, file) == 1){
                PrintPontos(pontos);
            }
            break;

        default:
            exit(1);
            break;
        }
    }


    return 0;
}