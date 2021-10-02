/*
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
For e.g. if a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".
Note : Consecutive count of every character in input string is less than equal to 9.
Input Format :

Input string S

Output Format :

Compressed string 

Sample Input:

aaabbccdsa

Sample Output:

a3b2c2dsa


*/

// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.
#include <bits/stdc++.h>
using namespace std;

void stringCompression(char input[]) {
    // Write your code here
    string ans="";
    
    for(int i=0;input[i]!=0;){
        int j=i+1;
        while(input[i]==input[j]){
            j++;
        }
        int c=j-i;
        //cout<<input[i]<<endl;
        //cout<<char(48+c)<<endl;
        //cout<<ans<<endl;
        char cd='0'+c;
        if (c!=0 && c!=1){
            ans+=input[i];
            ans+=(char)(cd);
        }
        else
            ans+=input[i];
        i=j;
    }
    strcpy(input,ans.c_str());

}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}
