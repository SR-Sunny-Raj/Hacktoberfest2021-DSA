#include <iostream>
using namespace std;

int factorial(int num){

    if(num==0)
    return 1;
    else
    return num*factorial(num-1);
}//factorial

int main(){
    
    int num=5;

    cout<<"The factorial of "<<num<<" is "<< factorial(num);
    return 0;
}//main