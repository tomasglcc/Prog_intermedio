/**
 * Projeto intermedio IST, rumo ao 20
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int opcao;
    /* Impressao no ecra das opcoes disponiveis */

    printf("Lista de opcoes:\n");
    printf("0 - Fim\n");
    printf("1 - Mostrar o baralho\n");
    printf("2 - Baralhar o baralho\n");
    printf("3 - Visualizar todas as jogadas do ultimo jogo\n");
    printf("4 - Jogar\n");

    /* Input da opcao pelo user*/
    printf("Selecione a opcao:\n");
    scanf("d\n", &opcao);


    switch (opcao)
    {
      case 0:
        prinf("O programa terminou\n");
        break;
      case 1:

      case 2:

      case 3:

      case 4:

      default:
      prinf("O input nao e valido");

    }


    return 0;
  }
