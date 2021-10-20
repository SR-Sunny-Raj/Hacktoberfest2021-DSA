#include <stdio.h>
//Program used to make a 3X3 matrix using 2-D Array.
int main()
{
    int matrix[3][3];
    int i,j;
    printf("This program will print a 3X3 matrix:\n\n");
    for ( i = 0; i <= 2; i++)
    {
        for ( j = 0; j <= 2; j++)
        {
            printf("Enter the numbers row wise:");
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\n\n\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSo this is the matrix form of numbers or also known as 2-D array.");
    return 0;
}

//Output:
// This program will print a 3X3 matrix:

// Enter the numbers row wise:1
// Enter the numbers row wise:2
// Enter the numbers row wise:3
// Enter the numbers row wise:4
// Enter the numbers row wise:5
// Enter the numbers row wise:6
// Enter the numbers row wise:7
// Enter the numbers row wise:8
// Enter the numbers row wise:9



// 1       2       3
// 4       5       6
// 7       8       9


// So this is the matrix form of numbers or also known as 2-D array.