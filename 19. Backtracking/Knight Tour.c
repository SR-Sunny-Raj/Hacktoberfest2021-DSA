// Knight tour using backtracking 
#include <stdio.h>

int n;
int count = 1;

int row[] = { 2, 1, -1, -2, -2, -1, 1, 2, 2 }; //Possible Moves for the Knight
int column[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };
 

int isValid(int x, int y, int N)
{
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return 0;
    }
 
    return 1;
}


void knight_tour(int n, int chess_board [n][n], int x, int y, int pos)
{
    
   chess_board[x][y] = pos; // visited
   if (pos >= n*n)
    {
	    printf("*****Solution %d****** \n", count);
		for (int i = 0; i < n; i++)
		    {
	            for (int j = 0; j < n; j++) {
	            	 printf(" %d   ", chess_board[i][j] );
	            }
	        printf("\n");
	        }
	        printf("\n");
	    count++;
        chess_board[x][y] = 0;
        return;
    }
 
    // check all moves
    for (int k = 0; k < 8; k++)
    {
    	
        int new_x = x + row[k];
        int new_y = y + column[k];
        if (isValid(new_x, new_y, n) == 1 && !chess_board[new_x][new_y]) {
            knight_tour(n, chess_board, new_x, new_y, pos + 1);
        }
    }
 
    chess_board[x][y] = 0;
}
 
int main()
{

    printf("Enter the value n ( n * n Chess board ) :  ");
    scanf("%d", &n);
	int chess_board[n][n];
    memset(chess_board, 0, sizeof chess_board);
    int pos = 1;
    
    int row_num, col_num;
    
    printf("Enter the initial Co-ordinates (Row number) : ");
    scanf("%d", &row_num);
    
    printf("Enter the initial Co-ordinates (Column number) : ");
    scanf("%d", &col_num);
    knight_tour(n, chess_board, row_num, col_num, pos);
	printf(" Total number of solutions are : %d \n", count);

	return 0;
}
