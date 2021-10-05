/* Problem Statement: Implement a code to solve a Godoku example
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using std::cout;
using std::endl;
#define DIM 9
#define BLANK 0
#define BLANK2 "X"
#define SPACE " "
#define LINE "|"
#define NEW_ROW "-------------------------------------"
#define GRID_FULL std::make_pair(9, 9)

void print_grid(int grid[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		cout << SPACE << SPACE << SPACE << SPACE << endl;
		cout << NEW_ROW << endl;
		for (int j = 0; j < DIM; j++)
		{
			cout << SPACE;
			if (BLANK == grid[i][j])
			{
				cout << SPACE;
			}
			else
			{
				cout << grid[i][j];
			}
			cout << SPACE;
			cout << LINE;
		}
	}
	cout << endl << NEW_ROW << endl << endl;;
}

void convert(int grid[DIM][DIM], char grid2[DIM][DIM])
{
			for (int i = 0; i < DIM; i++)
	{ 		for (int j = 0; j < DIM; j++)
		{			
			if (grid[i][j]==1)
			{
				grid2[i][j]='A';
			}
			else if(grid[i][j]==2)
			{
				grid2[i][j]='B';
			}
			else if(grid[i][j]==3){
				grid2[i][j]='C';
			}
			else if(grid[i][j]==4){
				grid2[i][j]='D';
			}
			else if(grid[i][j]==5){
				grid2[i][j]='E';
			}
			else if(grid[i][j]==6){
				grid2[i][j]='F';
			}
			else if(grid[i][j]==7){
				grid2[i][j]='G';
			}
			else if(grid[i][j]==8){
				grid2[i][j]='H';
			}
			else if(grid[i][j]==9){
				grid2[i][j]='I';
			}
			else if (grid[i][j]==0){
				grid2[i][j]='X';
			}

		}

	}
}

void print_grid2(char grid2[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		cout << SPACE << SPACE << SPACE << SPACE << endl;
		cout << NEW_ROW << endl;
		for (int j = 0; j < DIM; j++)
		{
			cout << SPACE;
			if (grid2[i][j]=='X')
			{
				cout << SPACE;
			}
			else
			{
				cout << grid2[i][j];
			}
			cout << SPACE;
			cout << LINE;
		}
	}
	cout << endl << NEW_ROW << endl << endl;;
}

bool used_in_row(int grid[DIM][DIM], int row, int num)
{
	for (int col = 0; col < DIM; col++)
		if (grid[row][col] == num)
		{
			return true;
		}
	return false;
}

bool used_in_col(int grid[DIM][DIM], int col, int num)
{
	for (int row = 0; row < DIM; row++)
		if (grid[row][col] == num)
		{
			return true;
		}
	return false;
}

bool used_in_box(int grid[DIM][DIM], int box_start_rpw, int box_start_col, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + box_start_rpw][col + box_start_col] == num) 
			{
				return true;
			}
	return false;
}

bool is_safe(int grid[DIM][DIM], int row, int col, int num)
{
	return !used_in_row(grid, row, num) &&
		!used_in_col(grid, col, num) &&
		!used_in_box(grid, row - row % 3, col - col % 3, num);
}

std::pair<int, int> get_unassigned_location(int grid[DIM][DIM])
{
	for (int row = 0; row < DIM; row++)
		for (int col = 0; col < DIM; col++)
			if (grid[row][col] == BLANK)
			{
				return std::make_pair(row, col);
			}
	return GRID_FULL;
}

bool solve_soduko(int grid[DIM][DIM])
{
	if (GRID_FULL == get_unassigned_location(grid))
	{
		return true; 
	}

	std::pair<int, int> row_and_col = get_unassigned_location(grid);
	int row = row_and_col.first;
	int col = row_and_col.second;

	for (int num = 1; num <= 9; num++)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;

			if (solve_soduko(grid))
			{
				return true;
			}

			grid[row][col] = BLANK;
		}
	}
	return false; 
}

 

int main()
{
	cout << "********************************\n\n\tGodoku Solver\n\n********************************" << endl << endl;

	int grid[DIM][DIM] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0 },
						   { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
						   { 0, 2, 0, 0, 0, 6, 9, 0, 4 },
						   { 0, 0, 1, 0, 0, 0, 0, 2, 0 },
						   { 5, 0, 0, 0, 7, 0, 0, 0, 0 },
						   { 0, 0, 6, 0, 0, 0, 8, 0, 0 },
						   { 0, 0, 0, 4, 0, 5, 0, 0, 0 },
						   { 9, 0, 0, 2, 0, 0, 0, 0, 0 },
						   { 0, 0, 0, 0, 0, 0, 0, 1, 0 } };
	char grid2[DIM][DIM];

	convert(grid,grid2);					   
						   

	print_grid2(grid2);


	if (true == solve_soduko(grid))
	{
		convert(grid,grid2);
		print_grid2(grid2);
	}
	else
	{
		cout << "No solution exists for the given Goduko" << endl << endl;
	}

	return 0;
}