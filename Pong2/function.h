#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <unistd.h>

extern int bolaX;
extern int bolaY;
extern int velocidadeX;
extern int velocidadeY;
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
void AtualizarBola();
void LimparTela();


#endif