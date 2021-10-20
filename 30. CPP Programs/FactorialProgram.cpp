#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int number, fact=1;
    cout<<"Enter a number, which factorial you want :- ";
    cin>>number;
    for(int i = 1; i <= number; i++){
        fact = fact*i;
    }
    cout<<"\nFactorial is :- "<<fact;
    getch();
}
