/*
 * Projeto intermedio IST, rumo ao 20
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAXCARTAS 36

void lista()
{
   printf("Lista de opcoes:\n");
   printf("0 - Fim\n");
   printf("1 - Mostrar o baralho\n");
   printf("2 - Baralhar o baralho\n");
   printf("3 - Visualizar todas as jogadas do ultimo jogo\n");
   printf("4 - Jogar\n");
}

int main()
{
    int opcao;
    /* Impressao no ecra das opcoes disponiveis */

    lista();


    printf("Selecione a opcao:\n");
    scanf("%d", &opcao);

    do {
      switch (opcao)
      {
        case 0:
          printf("O programa terminou\n");
          break;
        case 1:
          printf("O programa terminou\n");

        case 2:
          printf("O programa terminou\n");

        case 3:
          printf("O programa terminou\n");

        case 4:
        printf("O programa terminou\n");

        default:
        printf("O input nao e valido");

      }

    }
    while(opcao != 0 );


return 0;
}
