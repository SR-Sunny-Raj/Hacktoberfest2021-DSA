

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char a[3][50];
    int i,j,k,len;
    cout<<"\nEnter 3 strings: \n";

    for(i=0;i<3;i++)
    {
        cout<<"\nEnter [ "<<i+1<<" ] String :: ";
        gets(a[i]);
    }

    cout<<"\nThe Array of Original Strings :: \n";

    for(i=0;i<3;i++)
    {
        cout<<"\n"<<a[i]<<" \n";
    }

    cout<<"\nThe Array of Reversed Strings :: \n";

    for(i=0;i<3;i++)
    {
        cout<<"\n";
        len=strlen(a[i]);
        for(j=0,k=len-1;k>=0;j++,k--)
        {
            cout<<a[i][k];
        }
        cout<<" \n";
    }

    return 0;
}
