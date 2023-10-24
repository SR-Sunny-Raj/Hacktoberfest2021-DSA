// Write a C++ Program to find number is even or odd using function.
// complexity = 3
#include<iostream>

using namespace std;
void fun(int x=0);
int main()
{
    int num=0;
    cout << "Enter number "<< endl;
    cin >> num;

    fun (num);
}
void fun (int x)
{
    if (x % 2== 0)
    cout <<"Even";
    else 
    cout << "Odd";
}