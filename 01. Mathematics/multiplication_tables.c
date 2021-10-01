/* A program to
 * take a number as input and 
 * print the multiplication table for it.
 */

#include <stdio.h>

/*Creating a user defined function*/
void tables(int num)
{
    int i;

    printf("\nThe multiplication table of %d is : \n", num );

    for(i=1; i<=10; i++)
    {
        printf("%d X %d = %d\n", num, i, (num*i) );
    }
}

/*The driver code*/
int main(void)
{
    int num;

    /* Input a number to print table */
    printf("Enter the number : ");
    scanf("%d", &num);

    /*Function call*/
    tables(num);

    return 0;
}
