#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){
    pontuacao pontos;
    int op;
    FILE *file;
    file = fopen("pontos.txt", "w");

    if(file == NULL){
        exit(1);
    }


    while(1){
        puts("1 - Jogar\n2 - Ajuda\n3 - Pontuacao\n4 - Sair\n");
        printf("Insira a opçao: ");
        scanf("%d", &op);

        switch (op){
        case 1:
            Tela();
            break;
        case 2:
            break;

        case 3:

            puts("\n\nPONTUACAO");
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