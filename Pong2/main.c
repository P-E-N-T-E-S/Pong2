#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <unistd.h>


int main(){
    pontuacao pontos;
    int op;
    FILE *file;
    file = fopen("pontos.txt", "w");

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
        while (1)
        {
            Tela();
            AtualizarBola();
            usleep(100000);
        }
        
            break;
        case 2:
            break;

        case 3:

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