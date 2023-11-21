#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int bolaX;
int bolaY;
int velocidadeX;
int velocidadeY;
int barraEsquerda;
int barraDireita;
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
void randomizar();
void remover(int x);
void AtualizarSegundaBola();
void PrintarEvento(int x);
#endif