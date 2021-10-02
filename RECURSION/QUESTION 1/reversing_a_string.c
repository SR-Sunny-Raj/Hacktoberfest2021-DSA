#include<stdio.h>
#include<conio.h>

char* reverse(char* str);

void main()
{
    int a, b, c;
    char str[70];
    char *rev;
    printf("Enter the string:\t");
    scanf("%s", str);
    rev = reverse(str);
    printf("The reversed string is: %s\n", rev);
    getch();
}

char* reverse(char *str)
{
    static int a = 0;
    static char rev[100];
    if(*str)
    {
        reverse(str+1);
        rev[a++] = *str;
    }
    return rev;
}