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
     printf("\nLista de opcoes:\n");
     printf("0 - Fim\n");
     printf("1 - Mostrar o baralho\n");
     printf("2 - Baralhar o baralho\n");
     printf("3 - Visualizar todas as jogadas do ultimo jogo\n");
     printf("4 - Jogar\n\n\n");
}

void mostrar_baralho(char baralho[MAXCARTAS][3])
{
  int k;

     for (k = 0; k < 36; k++)
     {
        printf("\t%s\n", baralho[k]);
     }
}


void baralhar(char baralho[MAXCARTAS][3])
{
  int loop1, j;
  char teste[MAXCARTAS][3];

  srand(time(NULL));

  printf("\t Ja esta baralhado!\n\n\n");
    for (loop1 = 0; loop1 < 36; loop1++)
    {

      j = rand() % 36;
        if (j == loop1 || ( j >= loop1))
        {
          strcpy(teste[4], baralho[j]);
          strcpy(baralho[j], baralho[loop1]);
          strcpy(baralho[loop1], teste[4]);
    }
          else
          {
            int k = loop1 - j;
            int l = j + k;
              strcpy(teste[4], baralho[l]);
              strcpy(baralho[l], baralho[loop1]);
              strcpy(baralho[loop1], teste[4]);
          }

    }
}




void jogar(char baralho[MAXCARTAS][3])
{
  char virtplayer[MAXCARTAS/2][3];
  char humplayer[MAXCARTAS/2][3];
  /*int q, p, z, a;*/
  int z;

    strcpy(humplayer[0],baralho[0]);
    strcpy(humplayer[1],baralho[1]);
    strcpy(humplayer[2],baralho[2]);

    strcpy(virtplayer[0],baralho[3]);
    strcpy(virtplayer[1],baralho[4]);
    strcpy(virtplayer[2],baralho[5]);


    for (z = 0; z < 3; z++)
    {
      printf("\n%s  \n", humplayer[z]);
    }
    for (z = 0; z < 3; z++)
    {
      printf("\n%s \n", virtplayer[z]);
    }


}


int main()
{
    int opcao;
    char baralho[MAXCARTAS][3] = {"1C","2C","3C","4C","5C","6C","7C","8C","9C","1E","2E","3E","4E","5E","6E","7E","8E","9E","1O","2O","3O","4O","5O","6O","7O","8O","9O","1P","2P","3P","4P","5P","6P","7P","8P","9P"};



      printf("\t\t\tBem vindo ao Jogo!\n\n\n\n");

      lista();
      printf("Selecione a opcao:\n");
      scanf("%d", &opcao);

      do
      {
        switch (opcao)
        {
          case 0:
            printf("O programa terminou\n");
            break;
          case 1:
            mostrar_baralho(baralho);
            lista();
            fflush( stdout );
            printf("Selecione a opcao:\n");
            scanf("%d", &opcao);
            break;
          case 2:
            baralhar(baralho);
            lista();
            fflush( stdout );
            printf("Selecione a opcao:\n");
            scanf("%d", &opcao);
            break;
          case 3:
            jogar(baralho);
            lista();
            fflush( stdout );
            printf("Selecione a opcao:\n");
            scanf("%d", &opcao);
            break;
          case 4:
            jogar(baralho);
            lista();
            fflush( stdout );
            printf("Selecione a opcao:\n");
            scanf("%d", &opcao);
            break;
          default:
            printf("O input nao e valido\n");
          }

        } while(opcao != 0 );

return 0;
}
