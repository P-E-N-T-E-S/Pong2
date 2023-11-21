#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <unistd.h>
#include <time.h>

extern int bolaX;
extern int bolaY;
extern int velocidadeX;
extern int velocidadeY;
extern int barraEsquerda;
extern int barraDireita;
#define altura 20
#define largura 50


typedef struct pontuacao{
    int player1;
    int player2;
    struct pontuacao *next;

}pontuacao;

void Tela();
void EscreverArquivo();
void PrintArquivo();
void AdicionarPonto(int p1, int p2);
void LiberarPonto();
void AtualizarBola();
void LimparTela();
void Tempo();
int radom();
void remover(int x);
void AtualizarSegundaBola();
#endif