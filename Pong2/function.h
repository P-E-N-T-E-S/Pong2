#include <stdio.h>
#define altura 20
#define largura 50


typedef struct pontuacao{
    int player1;
    int player2;
    struct pontuacao *next;

}pontuacao;

void Tela();
void EscreverArquivo(FILE* arquivo, pontuacao players);
void PrintPontos(pontuacao pontos);
