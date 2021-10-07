/*1
2 3
4 5 6
7 8 9 10*/
#include<stdio.h>
int main(){
    int i, j, space, value=1,no=1;
    for(i=1;i<=10;++i)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",no);
            no++;
        }
        printf("\n");
    }
    return 0;
}
