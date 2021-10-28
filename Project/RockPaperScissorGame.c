// try to use a char array to display the turn it's stone paper or scisor..............
/***It's a rock-paper-scissor game using basic c***/
/***@Author: Soumyadip Ghosh***/
//Github Account : https://github.com/SoumyadipGhosh23

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    
    int a = 1, input, player = 0, computer = 0, g; 
    while (a < 4)
    {
        printf("Enter 0 for STONE/1 for PAPER/2 for SCISOR: ");
        scanf("%d", &input);
        srand(time(NULL));
        int comp = rand() % 3;
        if (input == comp)
        {
            printf("DRAW\n");
        }
        else if (input == 0 && comp == 1)
        {
            computer++;
            printf("Computer Won\n");
        }
        else if (input == 1 && comp == 2)
        {
            computer++;
            printf("Computer Won\n");
        }
        else if (input == 2 && comp == 0)
        {
            computer++;
            printf("Computer Won\n");
        }
        else if (comp == 0 && input == 1)
        {
            player++;
            printf("Player Won\n");
        }
        else if (comp == 1 && input == 2)
        {
            player++;
            printf("Player Won\n");
        }
        else if (comp == 2 && input == 0)
        {
            player++;
            printf("Player Won\n");
        }
        a++;
    }

    if (player > computer)
    {
        printf("\nYOU WON\n");
    }
    else if (player == computer)
        printf("\nDRAW\n");
    else if (player < computer)
        printf("\nYOU LOSE\n");


    return 0;
}
