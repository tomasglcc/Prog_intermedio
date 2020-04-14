#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCARTAS 36


/*
Imprime no stdout as cartas que cada jogar tem na soa mao
*/

void mostra_cartas(char humano[3][3], char maquina[3][3], FILE *fp) {
    int i;

    printf("JV: ");
    for (i = 0; i < 3; i++) {
        printf("%s ", maquina[i]);
    }

    printf("*** JH: ");
    for (i = 0; i < 3; i++) {
        printf("%s ", humano[i]);
    }
    printf("\n");

    fprintf(fp, "JV: ");
    for (i = 0; i < 3; i++) {
        fprintf(fp, "%s ", maquina[i]);
    }
    fprintf(fp, "*** JH: ");
    for (i = 0; i < 3; i++) {
        fprintf(fp, "%s ", humano[i]);
    }
    fprintf(fp, "\n");
}

/*Imprime no stdout as cartas que cada jogar tem na soa mao,
 * como se trata da penultima jogada, ambos os jogadores tem
 * apenas 2 cartas na sua mao*/

void mostracartas3(char humplayer[3][3], const int carta[2], char virtplayer[3][3], FILE *fp) {
    if (carta[0] == 2) {
        printf("JV: ");
        printf("%s %s ", virtplayer[0], virtplayer[1]);
        fprintf(fp, "JV: ");
        fprintf(fp, "%s %s ", virtplayer[0], virtplayer[1]);
        memcpy(virtplayer[2], "00", 2);
    }
    if (carta[0] == 1) {
        printf("JV: ");
        printf("%s %s ", virtplayer[0], virtplayer[2]);
        fprintf(fp, "JV: ");
        fprintf(fp, "%s %s ", virtplayer[0], virtplayer[2]);
        memcpy(virtplayer[1], "00", 2);
    }
    if (carta[0] == 0) {
        printf("JV: ");
        printf("%s %s", virtplayer[1], virtplayer[2]);
        fprintf(fp, "JV: ");
        fprintf(fp, "%s %s", virtplayer[1], virtplayer[2]);
        memcpy(virtplayer[0], "00", 2);
    }

    if (carta[1] == 2) {
        printf("*** JH: ");
        printf("%s %s\n", humplayer[0], humplayer[1]);
        fprintf(fp, "*** JH: ");
        fprintf(fp, "%s %s\n", humplayer[0], humplayer[1]);
        memcpy(humplayer[2], "00", 2);
    }
    if (carta[1] == 1) {
        printf("*** JH: ");
        printf("%s %s\n", humplayer[0], humplayer[2]);
        fprintf(fp, "*** JH: ");
        fprintf(fp, "%s %s\n", humplayer[0], humplayer[2]);
        memcpy(humplayer[1], "00", 2);
    }
    if (carta[1] == 0) {
        printf("*** JH: ");
        printf("%s %s\n", humplayer[1], humplayer[2]);
        fprintf(fp, "*** JH: ");
        fprintf(fp, "%s %s\n", humplayer[1], humplayer[2]);
        memcpy(virtplayer[0], "00", 2);
    }
}

/*
Imprime no stdout a ultima carta do JH
*/


/*
Imprime no stdout as 4 cartas presentes no topo do baralho
*/

void topobaralho(int ndj2, char baralho[MAXCARTAS][3], int ndj, FILE *fp) {
    int i;

    printf("---------------Jogada %d---------------\n", (ndj + 1));
    fprintf(fp, "---------------Jogada %d---------------\n", (ndj + 1));
    if (ndj2 < 27) {
        printf("Baralho: ");
        fprintf(fp, "Baralho: ");
        for (i = ndj2 + 6; i < ndj2 + 6 + 4; i++) {
            printf("%s ", baralho[i]);
            fprintf(fp, "%s ", baralho[i]);
        }
        printf("\n");
        fprintf(fp, "\n");
    } else if (ndj2 == 28) {
        printf("Baralho: ");
        fprintf(fp, "Baralho: ");
        for (i = ndj2 + 6; i < ndj2 + 6 + 2; i++) {
            printf("%s ", baralho[i]);
            fprintf(fp, "%s ", baralho[i]);
        }
        printf("-- --\n");
        fprintf(fp, "-- --\n");
    } else {
        printf("\nBaralho: ");
        fprintf(fp, "\nBaralho: ");
        printf("-- -- -- --\n");
        fprintf(fp, "-- -- -- --\n");
    }
}

/*
Baralha o deck de cartas
*/

void baralhar(char baralho[MAXCARTAS][3]) {
    int loop1, j;
    char teste[MAXCARTAS][3];

/*
gera um seed
*/

    srand((unsigned int) time(NULL));

    printf("\t Ja esta baralhado!\n\n\n");


    for (loop1 = 0; loop1 < 36; loop1++) {
/*
 gera um valor entre 0 e 35
*/

        j = rand() % 36;
/*
troca a posicao de indice loop1 com a posicao de indice j
*/

        if (j >= loop1) {
            strcpy(teste[4], baralho[j]);
            strcpy(baralho[j], baralho[loop1]);
            strcpy(baralho[loop1], teste[4]);
        }
/*
 Se o valor gerado pela funcao rand for inferior ao indice da iteracao,
*/
/*
           * entao "j" sera igual a "loop1"
*/

        else {
            int l = j;
            strcpy(teste[4], baralho[l]);
            strcpy(baralho[l], baralho[loop1]);
            strcpy(baralho[loop1], teste[4]);
        }

    }
}

/*
Inicializa a primeira mao de cartas para ambos os jogadores
*/

void primeiramao(char virtplayer[3][3], char humplayer[3][3], char baralho[MAXCARTAS][3]) {
    int i;

/*
  As 3 primeiras cartas do baralho soa colocadas na mao do JV
*/

    for (i = 0; i < 3; i++) {
        strcpy(virtplayer[i], baralho[i]);
    }

    /*As 3 primeiras cartas do baralho soa colocadas na mao do JV.
   *  As cartas que vao para o JH sao as que estao nas posicoes:
   *  3, 4 e 5, i-3 -> colocar nas posicoes 0, 1 e 2 do JH   */

    for (i = 3; i < 6; i++) {
        strcpy(humplayer[i - 3], baralho[i]);
    }
}

/*
Compara as cartas da dada mao, selecionada no argumento da funcao. Returna o indice da carta mais alta
*/

int cartamaisalta(char mao[3][3]) {
    int i, u = 0;

    for (i = 1; i < 3; i++) {
        if (mao[i][0] > mao[u][0])
            u = i;
    }
    return u;
}

/*
Compara as cartas da dada mao, selecionada no argumento da funcao. Returna o indice da carta mais baixa
*/

int cartamaispequena(char mao[3][3]) {
    int i, k = 0;

    for (i = 1; i < 3; i++) {
        if (mao[i][0] < mao[k][0])
            k = i;
    }
    return k;
}
void ultcartahumano(char humplayer[3][3], FILE *fp) {
    int i;

    for (i = 0; i < 3; i++) {
        if ((strcmp( &humplayer[i][1], "0")) != 0) {
            printf("JH: %s ", humplayer[i]);
            fprintf(fp, "JH: %s  ", humplayer[i]);
            return;
        }
    }
}

void ultcartamaquina(char virtplayer[3][3], FILE *fp) {
    int i;

    for (i = 0; i < 3; i++) {
        if ((strcmp( &virtplayer [i][1] , "0")) != 0) {
            printf("\nJV: %s *** ", virtplayer[i]);
            fprintf(fp, "\nJV: %s *** ", virtplayer[i]);
            return;
        }
    }
}

/*
Le o stdin guardando o resultado na variabel tmporaria "a", returnando o indice da carta escoolhida
*/

int jogadahumana(char humplayer[3][3]) {
    int i, u, c;
    char a[5];
    printf("\nEscolhe a carta Humano!\n");
    scanf("%s", a);

    u = -1;
/*a funcao memcmp retorna o valor 0, guardando esse valor em "c",
     * se o conteudo dos dois blocos de memoria forem iguais,
     * a variavel tmporaria "u" sera igual ao indice da iteracao ciclo "for",
     * retornando o valor u no fim*/

    for (i = 0; i < 3; i++) {
        c = memcmp(a, humplayer[i], 2);
        if (c == 0) {
            u = i;
        }
    }
    if (u == -1) {
        puts("Essa carta nao e valida fdp");
        exit(0);

    } else {
        return u;
    }
}

/*
Copia a primeira carta no topo do baralho, para o lugar da carta que foi escolhida na jogada anterior
*/

void darcarta_humano(char baralho[MAXCARTAS][3], const int carta[2], char humplayer[3][3], int ndj) {

    if (ndj == -2) {
        return;
    }
        /*ndj -> numero da jogada, +6 -> "compensar" as 6 primeiras cartas do baralho(3 para o JH e 3 para o JV*/

    else {
        strcpy(humplayer[carta[1]], baralho[(ndj + 6)]);
    }
}

/*Copia a segunda carta no topo do baralho, para o lugar da carta que foi escolhida na jogada anterior*/

void darcarta_virt(char baralho[MAXCARTAS][3], const int carta[2], char virtplayer[3][3], int ndj) {

    if (ndj == -2) {
        return;
    }
        /*ndj -> numero da jogada, +6 -> "compensar" as 6 primeiras cartas do baralho(3 para o JH e 3 para o JV)*/

    else {
        strcpy(virtplayer[carta[0]], baralho[(ndj + 7)]);
    }
}

/*Realiza a decisao de quem ganha, notando que o JV foi quem inicializou a jogada*/

int comparador_inicial(const int carta[2], char humplayer[3][3], char virtplayer[3][3]) {
    int pnt = 0;
    if (humplayer[carta[1]][1] == virtplayer[carta[0]][1] && humplayer[carta[1]][0] > virtplayer[carta[0]][0]) {
        pnt = 1;
    } else {
        pnt = -1;
    }
    return pnt;
}

/*
Realiza a decisao de quem ganha, notando que o JH foi quem inicializou a jogada
*/

int comparador_cmchumano(const int carta[2], char humplayer[3][3], char virtplayer[3][3]) {
    int pnt = 0;

/*
compara os naipes e o valor das cartas
*/

    if (humplayer[carta[1]][1] == virtplayer[carta[0]][1] && humplayer[carta[1]][0] < virtplayer[carta[0]][0]) {
        printf("\nJV ganhou\n");
        pnt = -1;
    } else {
        printf("\nJH ganhou\n");
        pnt = 1;
    }
    return pnt;
}

/*Decide qual a carta a jogar contra a carta escolhida pelo humano,
* sendo que sera do mesmo naipe se o JV a tiver, caso contrario
* a carta mais baixa sera escolhida pelo JV*/

int AIcartas(char virtplayer[3][3], char humplayer[3][3], const int carta[2]) {
    int i, j, u = 0;
    char tmp[5];
    char maovirtual[3][3];
/*esta variavel tem o proposito de criar uma mao de cartas virtual
                            *com o intuito de encontrar a carta mais alta do naipe da carta
                            *que o JV escolheu, de um modo mais simples */


/*Guardar as cartas do mesmo naipe da carta selecionada pelo JH na matrix "maivirtual", se existirem*/


    for (i = 0; i < 3; ++i) {
        if (virtplayer[i][1] == humplayer[carta[1]][1]) {
            strcpy(maovirtual[i], virtplayer[i]);
        } else {
            strcpy(maovirtual[i], "00");
        }
    }

/*Colocar as cartas presentes na mao virtal por ordem crescente, optimizando o processo seguinte*/

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            if (maovirtual[i] > maovirtual[j]) {
                strcpy(tmp, maovirtual[i]);
                strcpy(maovirtual[i], maovirtual[j]);
                strcpy(maovirtual[j], tmp);
            }
        }
    }

    u = cartamaisalta(maovirtual);

/*Verifica se a carta que iria ser escolhida e do mesmo naipe da carta do JH, caso nao seja jogar a carta de menor valor*/

    if (virtplayer[u][1] != humplayer[carta[1]][1]) {
        u = cartamaispequena(virtplayer);
    }
    return u;
}

int AIcartas2(char virtplayer[3][3], char humplayer[3][3], const int carta[2]) {
    int i, u = 0;
    int indice = carta[1];
    char maovirtual[3][3];

    for (i = 0; i < 3; ++i) {
        if (virtplayer[i][1] == humplayer[indice][1]) {
            strcpy(maovirtual[i], virtplayer[i]);
        } else {
            strcpy(maovirtual[i], "00");
        }
    }

    u = cartamaisalta(maovirtual);
    if (virtplayer[u][1] != humplayer[indice][1]) {
        for (i = 0; i < 3; i++) {
            strcpy(maovirtual[i], virtplayer[i]);
        }
        u = cartamaispequena(maovirtual);
        u++;
    }
return u;
}
int clearlastplay(char virtplayer[3][3], char humplayer[3][3], const int carta[2], const int tmp[2]) {

    strcpy(virtplayer[carta[0]], "00");
    strcpy(humplayer[carta[1]], "00");
    strcpy(virtplayer[tmp[0]], "00");
    strcpy(humplayer[tmp[1]], "00");
}

/*
Imprime no stdout a carta escolhida pelo jogador humano e pelo computador
*/

void jogada(char humplayer[3][3], char virtplayer[3][3], const int carta[2], FILE *fp) {

    printf("Jogada: JV: %s *** JH: %s\n", virtplayer[carta[0]], humplayer[carta[1]]);
    fprintf(fp, "Jogada: JV: %s *** JH: %s\n", virtplayer[carta[0]], humplayer[carta[1]]);
}

/*
Imprime a contagem das jogadas, registando o vencedor da jogada
*/

void contagem(int *benny, int *humano, int lastwinner, FILE *fp) {

    if (lastwinner == 1) {
        (*humano)++;
    } else {
        (*benny)++;
    }
    printf("Contagem das jogadas: JV=%d *** JH=%d\n", (*benny), (*humano));
    fprintf(fp, "Contagem das jogadas: JV=%d *** JH=%d\n", (*benny), (*humano));
}

/*
Opcao 4, inicializa o jogo
*/

/*
ATENCAO o vecotr carta[], guarda o indice da carta jogada tanto pelo JV como pelo o JH
*/

void opcao4(char baralho[MAXCARTAS][3], char virtplayer[3][3], char humplayer[3][3], FILE *fp) {
    int ndj = 0, ndj2 = 0, lastwinner = 0, human_pnt = 0, benny_pnt = 0;
    int carta[2] = {0, 0};
    int tmp[2] = {0, 0};

    primeiramao(virtplayer, humplayer, baralho);
    for (ndj = 0, ndj2 = 0; ndj < 20 && ndj2 < 1000; ndj++, ndj2 = ndj2 + 2) {
        if (ndj < 16) {
            topobaralho(ndj2, baralho, ndj, fp);
            darcarta_humano(baralho, carta, humplayer, ndj2 - 2);
            darcarta_virt(baralho, carta, virtplayer, ndj2 - 2);
            mostra_cartas(humplayer, virtplayer, fp);
            if (lastwinner == 1) {
                carta[1] = jogadahumana(humplayer);
                tmp[1] = carta[1];
                carta[0] = AIcartas(virtplayer, humplayer, carta);
                tmp[0] = carta[0];
                lastwinner = comparador_cmchumano(carta, humplayer, virtplayer);
            } else {
                carta[0] = cartamaisalta(virtplayer);
                tmp[0] = carta[0];
                printf("O JV JOGA:  %s\n", virtplayer[carta[0]]);
                carta[1] = jogadahumana(humplayer);
                tmp[1] = carta[1];
                lastwinner = comparador_inicial(carta, humplayer, virtplayer);
            }
            jogada(humplayer, virtplayer, carta, fp);
            contagem(&benny_pnt, &human_pnt, lastwinner, fp);
        } else if (ndj == 16) {
            topobaralho(ndj2, baralho, ndj, fp);
            mostracartas3(humplayer, carta, virtplayer, fp);
/*
            printf("\n%s %s %s ::::: %s %s %s\n", virtplayer[0], virtplayer[1], virtplayer[2], humplayer[0], humplayer[1], humplayer[2]);
*/
            if (lastwinner == 1) {
                carta[1] = jogadahumana(humplayer);
                carta[0] = AIcartas2(virtplayer, humplayer, carta);
                lastwinner = comparador_cmchumano(carta, humplayer, virtplayer);
            } else {
                carta[0] = cartamaisalta(virtplayer);
                printf("O JV JOGA:  %s\n", virtplayer[carta[0]]);
                carta[1] = jogadahumana(humplayer);
                lastwinner = comparador_inicial(carta, humplayer, virtplayer);
            }
            jogada(humplayer, virtplayer, carta, fp);
            contagem(&benny_pnt, &human_pnt, lastwinner, fp);
            clearlastplay(virtplayer,humplayer,carta,tmp);
        } else if (ndj == 17) {
/*
            printf("\n%s %s %s ::::: %s %s %s\n", virtplayer[0], virtplayer[1], virtplayer[2], humplayer[0], humplayer[1], humplayer[2]);
*/
            topobaralho(ndj2, baralho, ndj, fp);
            ultcartamaquina(virtplayer, fp);
            ultcartahumano(humplayer, fp);
            if (lastwinner == 1) {
                carta[1] = jogadahumana(humplayer);
                carta[0] = cartamaisalta(virtplayer);
                lastwinner = comparador_cmchumano(carta, humplayer, virtplayer);
            } else {
                carta[0] = cartamaisalta(virtplayer);
                printf("\nO JV JOGA:  %s\n", virtplayer[carta[0]]);
                carta[1] = jogadahumana(humplayer);
                lastwinner = comparador_inicial(carta, humplayer, virtplayer);
            }
            jogada(humplayer, virtplayer, carta, fp);
            contagem(&benny_pnt, &human_pnt, lastwinner, fp);
        }
    }
}

void lista() {
    printf("\nLista de opcoes:\n");
    printf("0 - Fim\n");
    printf("1 - Mostrar o baralho\n");
    printf("2 - Baralhar o baralho\n");
    printf("3 - Visualizar todas as jogadas do ultimo jogo\n");
    printf("4 - Jogar\n\n\n");
}

void mostrar_baralho(char baralho[MAXCARTAS][3]) {
    int k;

    for (k = 0; k < 36; k++) {
        printf("\t%s\n", baralho[k]);
    }
}

int main() {

    int opcao;
    char ch;
    /*char baralho[MAXCARTAS][3] = {"1C","2C","3C","4C","5C","6C","7C","8C","9C","1E","2E","3E","4E","5E","6E","7E","8E","9E","1O","2O","3O","4O","5O","6O","7O","8O","9O","1P","2P","3P","4P","5P","6P","7P","8P","9P"};*/


    char baralho[MAXCARTAS][3] = {"1C", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C",
                                  "1E", "2E", "3E", "4E", "5E", "6E", "7E", "8E", "9E",
                                  "1O", "2O", "3O", "4O", "5O", "6O", "7O", "8O", "9O",
                                  "1P", "2P", "3P", "4P", "5P", "6P", "7P", "8P", "9P"};

    char virtplayer[3][3];
    char humplayer[3][3];
    FILE *fp;

    printf("\t\t\tBem vindo ao Jogo!\n\n\n\n");

    lista();
    printf("Selecione a opcao:\n");
    scanf("%d", &opcao);

    do {
        switch (opcao) {
            case 0:
                printf("O programa terminou\n");
                break;
            case 1:
                mostrar_baralho(baralho);
                lista();
                fflush(stdout);
                printf("Selecione a opcao:\n");
                scanf("%d", &opcao);
                break;
            case 2:
                baralhar(baralho);
                lista();
                fflush(stdout);
                printf("Selecione a opcao:\n");
                scanf("%d", &opcao);
                break;
            case 3:
                fp = fopen("bisca.txt", "r");
                if (fp == NULL) {
                    puts("O FICHEIRO NAO EXISTE");
                    exit(EXIT_FAILURE);
                }
                do {
                    ch = fgetc(fp);
                    putchar(ch);
                } while (ch != EOF);
                fclose(fp);
                lista();
                fflush(stdout);
                printf("Selecione a opcao:\n");
                scanf("%d", &opcao);
                break;
            case 4:
                fp = fopen("bisca.txt", "w");
                opcao4(baralho, virtplayer, humplayer, fp);
                fclose(fp);
                lista();
                fflush(stdout);
                printf("Selecione a opcao:\n");
                scanf("%d", &opcao);
                break;
            default:
                printf("O input nao e valido\n");
        }

    } while (opcao != 0);

    return 0;
}
