#include<iostream>
#include<string>
using namespace std;


//dynamic program to chaneg string alphabets to lowercase to uppercase


//logic 
//Firstly we will input the value of string 
//then we will iterate through the string till the end and fetch the ascii value of alphabets.
//in next step we will subtract 32 from ascii value of it is between 97 & 122 
//then we will print the update string


int main(){
    char input[100];

    cout<<"Enter the String"<<endl;
    cin>>input;

    for(int i=0;i<strlen(input);i++){
        if(input[i]>=97 && input[i]<=122){
            input[i] = input[i]-32;
        }
    }
    cout<<"uppercase string : "<<input<<endl;
    






}