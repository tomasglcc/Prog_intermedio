#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 44
#define MAXCARTAS 36


int main()
{

  int k;
  char baralho[MAXCARTAS][3] = {"1C","2C","3C","4C","5C","6C","7C","8C","9C","1E","2E","3E","4E","5E","6E","7E","8E","9E","1O","2O","3O","4O","5O","6O","7O","8O","9O","1P","2P","3P","4P","5P","6P","7P","8P","9P"};
  /* baralho[0] = "1C";    baralho[9] = "1E";    baralho[18] = "1O";   baralho[27] = "1P";
  *baralho[1] = "2C";    baralho[10] = "2E";   baralho[19] = "2O";   baralho[28] = "2P";
  *baralho[2] = "3C";    baralho[11] = "3E";   baralho[20] = "3O";   baralho[29] = "3P";
  *baralho[3] = "4C";    baralho[12] = "4E";   baralho[21] = "4O";   baralho[30] = "4P";
  *baralho[4] = "5C";    baralho[13] = "5E";   baralho[22] = "5O";   baralho[31] = "5P";
  *baralho[5] = "6C";    baralho[14] = "6E";   baralho[23] = "6O";   baralho[32] = "6P";
  *baralho[6] = "7C";    baralho[15] = "7E";   baralho[24] = "7O";   baralho[33] = "7P";
*  baralho[7] = "8C";    baralho[16] = "8E";   baralho[25] = "8O";   baralho[34] = "8P";
*  baralho[8] = "9C";    baralho[17] = "9E";   baralho[26] = "9O";   baralho[35] = "9P";
*/
  srand(time(NULL));

  for (k = 0; k < 36; k++)
  {
    printf("%d - %s\n", k, baralho[k]);

  }


/*  scanf("%d", &y);
  *printf("a carta e %s\n", baralho[y]);
*/
return 0;
}
