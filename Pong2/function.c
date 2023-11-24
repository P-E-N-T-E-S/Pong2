#include "function.h"
#include "keyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bolaX = 5;
int bolaY = 5;
int velocidadeX = 1;
int velocidadeY = 1;
int segundaBolaX = 10;
int segundaBolaY = 15;
int velocidadeX2 = -1;
int velocidadeY2 = -1;
int seg = 30;
int mim = 1;
int temp = 0;
int pass = 0;
int x = 0, val = 1, aux = 0;
struct pontuacao player;
struct pontuacao *head = NULL;
void Tela() {
  LimparTela();
  randomizar();
  PrintSd();
  for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
          if (j == 0 || j == largura - 1) {
              printf("%s█%s", COR_AZUL, COR_RESET);
          } else if ((i == 0 || i == altura - 1) && (j > 0 && j < largura - 1)) {
              printf("%s█%s", COR_AZUL, COR_RESET);
          } else if (j == 2 && (i >= barraEsquerda - 2 && i <= barraEsquerda + 2)) {
              printf("█");
          } else if (j == largura - 3 && (i >= barraDireita - 2 && i <= barraDireita + 2)) {
              printf("█");
          } else if (i == (int)bolaY && j == (int)bolaX) {
              printf("%s●%s", COR_VERMELHO, COR_RESET);
          } else if (aux == 1 && i == (int)segundaBolaY && j == (int)segundaBolaX) {
              printf("%s●%s", COR_VERMELHO, COR_RESET);
          } else if (j == largura / 2) {
              printf("|");
          } else {
              printf(" ");
          }
      }
      printf("\n");
  }
  PrintarEvento(x);

  if(x == 1){
    usleep(50000);
  }
  else{
    usleep(75000);
  }
}

void AdicionarPonto(int p1, int p2) {
  pontuacao *novo = (pontuacao *)malloc(sizeof(pontuacao));
  if (novo == NULL) {
    return;
  }

  novo->player1 = p1;
  novo->player2 = p2;
  novo->next = head;
  head = novo;
}

void LiberarPonto() {
  pontuacao *atual = head;
  pontuacao *prox;

  while (atual != NULL) {
    prox = atual->next;
    free(atual);
    atual = prox;
  }

  head = NULL;
}

void EscreverArquivo() {
  FILE *fptr = fopen("pontos.txt", "a");
  if (fptr == NULL) {
    exit(1);
  }

  fprintf(fptr, "Player 1: %d | Player 2: %d\n", head->player1, head->player2);
  fclose(fptr);
}

void PrintArquivo() {
  FILE *fptr = fopen("pontos.txt", "r");
  if (fptr == NULL) {
    exit(1);
  }

  char linha[100];
  while (fgets(linha, sizeof(linha), fptr) != NULL) {
    printf("%s", linha);
  }

  fclose(fptr);
}

void AtualizarBola() {
  bolaX += velocidadeX;
  bolaY += velocidadeY;

  if (bolaX <= 0) {
    player.player2 += 1 * val;
    velocidadeX = -velocidadeX;
  }

  if (bolaX >= largura - 1) {
    player.player1 += 1 * val;
    velocidadeX = -velocidadeX;
  }

  if (bolaY <= 0 || bolaY >= altura - 1) {
    velocidadeY = -velocidadeY;
  }

  if (bolaX == 2) {
    if (bolaY >= barraEsquerda - 2 && bolaY <= barraEsquerda + 2) {
      velocidadeX = -velocidadeX;
    }
  }

  if (bolaX == largura - 3 &&
      (bolaY >= barraDireita - 2 && bolaY <= barraDireita + 2)) {
    velocidadeX = -velocidadeX;
  }
}

void AtualizarSegundaBola() {
  if (aux == 1) {
    segundaBolaX += velocidadeX2;
    segundaBolaY += velocidadeY2;

    if (segundaBolaX <= 0) {
      player.player2 += 1 * val;
      velocidadeX2 = -velocidadeX2;
    }

    if (segundaBolaX >= largura - 1) {
      player.player1 += 1 * val;
      velocidadeX2 = -velocidadeX2;
    }

    if (segundaBolaY <= 0 || segundaBolaY >= altura - 1) {
      velocidadeY2 = -velocidadeY2;
    }

    if (segundaBolaX == 2) {
      if (segundaBolaY >= barraEsquerda - 2 &&
          segundaBolaY <= barraEsquerda + 2) {
        velocidadeX2 = -velocidadeX2;
      }
    }

    if (segundaBolaX == largura - 3 && (segundaBolaY >= barraDireita - 2 &&
                                        segundaBolaY <= barraDireita + 2)) {
      velocidadeX2 = -velocidadeX2;
    }
  }
}


void LimparTela() { system("clear"); }

void Tempo() {

  temp++;

  if (temp % 10 == 0) {
    seg--;
  }

  if (mim == 0 && seg == 0) {
    printf("O tempo acabou!\n");
    printf("Player 1: %d | Player 2: %d\n", player.player1, player.player2);
    AdicionarPonto(player.player1, player.player2);
    EscreverArquivo();
    LiberarPonto();
    keyboardDestroy();
    exit(1);
  }

  if (seg == 0) {
    mim--;
    seg = seg + 60;
  }
}

void remover(int x) {
  if (x == 1) {
    x = 0;
  }
  if(x == 2){
    aux = 0;
    x = 0;
  }
  if (x == 3) {
    val = 1;
    x = 0;
  }
}

void randomizar(){
    srand(time(NULL));
    if (temp == 300) {
      x = 1 + rand() % 3;
      printf("%d", x);
    if (x == 1) {
      x = 1;
    }
    else if (x == 2) {
      aux = 1;
    }
    else if (x == 3) {
      val = 2;
    }
  }

  if (temp == 600) {
    remover(x);
    x = 1 + rand() % 3;
    printf("%d", x);
    if (x == 1) {
      x = 1;
    }
    else if (x == 2) {
      aux = 1;
    }
    else if (x == 3) {
      val = 2;
    }
  }
}

void PrintarEvento(int x){
  if(x == 1){
    printf("\n\t\tVelocidade em 2X, Cuidado!\n\n");
  }
  if(x == 2){
    printf("\n\t\tO dobro de bolas? Agora prove seu valor!\n\n");
  }
  if(x == 3){
    printf("\n\tPontuação duplicada, essa é a hora de virar!\n\n");
  }
}



void PrintSd(){
  printf("%s\n\t\t\t\t\t %02d:%02d\n\n%s",COR_VERDE, mim, seg, COR_RESET);
  for (int i = 0; i < 23; i++) {
    printf(" ");
  }
  printf("%s%d | %d\n\n%s", COR_VERDE, player.player1, player.player2, COR_RESET);
}