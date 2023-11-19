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
int x, val = 1;
struct pontuacao player;
struct pontuacao *head = NULL;

void Tela() {
  LimparTela();

  printf("\t\t\t\t\t  %d | %d \n\n", player.player1, player.player2);

  for (int i = 0; i < altura; i++) {
    for (int j = 0; j < largura; j++) {
      if (j == 0 || j == largura - 1) {
        printf("░");
      } else if ((i == 0 || i == altura - 1) && (j > 0 && j < largura - 1)) {
        printf("░");
      } else if (j == 2 && (i >= barraEsquerda - 2 && i <= barraEsquerda + 2)) {
        printf("█");
      } else if (j == largura - 3 &&
                 (i >= barraDireita - 2 && i <= barraDireita + 2)) {
        printf("█");
      } else if (i == (int)bolaY && j == (int)bolaX) {
        printf("O");
      }else if (temp >= 500 && i == (int)segundaBolaY && j == (int)segundaBolaX) {
        printf("o");
      }else {
        printf(" ");
      }
    }
    printf("\n");
  }

  if (temp == 300) {
    x = radom();
    if(x == 1){
      velocidadeX *= 2;
      velocidadeY *= 2;
    }
    if(x == 3){
      val = 2;
    }
  }

  if (temp == 600) {
    remover(x);
    radom();
  }

  if (mim == 0 && seg == 0) {
    printf("O tempo acabou !");
    EscreverArquivo(head);
    PrintPontos();
    exit(1);
  }

  Tempo();
}

void EscreverArquivo(struct pontuacao *head) {
    FILE *fptr;
    fptr = fopen("pontos.txt", "wb");

    if (fptr == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    } else {
        struct pontuacao *temp = head;

        while (temp != NULL) {
            fwrite(temp, sizeof(struct pontuacao), 1, fptr);
              temp = temp->next;
        }

        fclose(fptr);
    }
}

void PrintPontos() {
    FILE *fptr;
    fptr = fopen("pontos.txt", "rb");

    if (fptr == NULL) {
        exit(1);
    } else {
        struct pontuacao pontos;

        printf("\n\tPlayer 1: %d\n", player.player1);
        printf("\tPlayer 2: %d\n", player.player2);
        puts("==================================");

        fseek(fptr, 0, SEEK_SET);
        while (fread(&pontos, sizeof(struct pontuacao), 1, fptr) == 1) {
            printf("\n\tPlayer 1: %d\n", pontos.player1);
            printf("\tPlayer 2: %d\n", pontos.player2);
            puts("==================================");
        }

        fclose(fptr);
    }
}

void AtualizarBola() {
  bolaX += velocidadeX;
  bolaY += velocidadeY;

  if (bolaX <= 0) {
    player.player2 += 1*val;
    velocidadeX = -velocidadeX;
  }

  if (bolaX >= largura - 1) {
    player.player1 += 1*val;
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
  if(temp >= 500){
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
      if (segundaBolaY >= barraEsquerda - 2 && segundaBolaY <= barraEsquerda + 2) {
        velocidadeX2 = -velocidadeX2;
      }
    }

    if (segundaBolaX == largura - 3 && (segundaBolaY >= barraDireita - 2 && segundaBolaY <= barraDireita + 2)) {
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
    printf("O tempo acabou !");
    keyboardDestroy();
    exit(1);
  }
  printf("\n\t\t\t\t\t %02d:%02d\n\n", mim, seg);

  if (seg == 0) {
    mim--;
    seg = seg + 60;
  }
}

int radom(){
  int x = rand() % 3 + 1;
  return x;
}

void remover(int x){
  if(x == 1){
    velocidadeX /= 2;
    velocidadeY /= 2;
  }
  if(x == 3){
    val = 1;
  }
}