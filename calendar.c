/* A program to take an input year from the user
*  And display that year's :- Calender using user defined function in c.
*/
#include <stdio.h>

/*User defined function*/
void gotoxy(int x,int y)
{
    while(y--)printf("\n");
    while(x--)printf(" ");
}

/*The month handle function*/
void printmonth(int day,int start)
{
    gotoxy(5,0);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat");
    gotoxy(10,2);
    for(int i=1;i<start;i++)printf("   ");
    for(int i=1;i<=day;i++){
        printf("%2d",i);
        if((i-1+start)%7==0){printf("\n");gotoxy(10,0);}
    }
    gotoxy(0,3);
}

/*The driver code*/
int main(void)
{
    int year,start=2,day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char name[][4]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

    /*Taking input from the user*/
    printf("Enter Year\n");
    scanf("%d",&year);
    
    /*Algorithm*/
    if((year%400)==0) day[1]=29;
    else if((year%100)==0) day[1]=28;
    else if((year%4)==0) day[1]=29;
    year--;
    start=(start+year)%7;
    start+=(year/4)-(year/100)+(year/400);
    start%=7;
    gotoxy(0,3);

    /*Incrementor*/
    for(int i=0;i<12;i++)
    {
        printf("%5s",name[i]);
        printmonth(day[i],start);
        start=(start+day[i]-1)%7+1;
    }

    gotoxy(0,15);

    return 0;
}
