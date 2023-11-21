#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    int num2[40];
    srand(time(NULL));

    for (i; i < 3; i++)
    {
        num2[i] = 1 + rand() % 3;
    }
    printf("\n\n");
    for(i = 0; i < 3; i++){
        printf("%d ", num2[i]);
    }
    printf("\n\n");
}