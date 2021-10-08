/*
Forms the pattern on the lines of:-
* * *
* *
*

*/
#include<iostream>
using namespace std;
int main(){
    int i, j;
    cout<<"Enter the number of rows\n";
    cin>>i;
    for(;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            cout<<"* ";
        }
        cout<<'\n';
    }
    return 0;
}
