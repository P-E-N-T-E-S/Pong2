#include "function.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *fptr;
    int op;
    Pontos pontos;
    fptr = fopen("pontuacao.dat", "ab+");

    if (fptr == NULL)
    {
        exit(1);
    }

    fflush(fptr);
    fseek(fptr, 0, 0);

    while (1)
    {
        printf(" 1 - Iniciar \n 2 - Pontuacao\n 3 - Sair\n");
        printf("Opçao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            break;

        case 2:
            while (fread(&pontos, sizeof(Pontos), 1, fptr) == 1){
                Pontuacao(pontos);
            }
            break;
        
        
        default:
            puts("\n\nATÉ MAIS!");
            puts("==================================");
            exit(1);
        }

    }
    
    
    return 0;
}