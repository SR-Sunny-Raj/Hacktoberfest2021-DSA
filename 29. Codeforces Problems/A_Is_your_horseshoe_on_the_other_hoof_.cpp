// Problem link : https://codeforces.com/problemset/problem/228/A

#include<iostream>
using namespace std;

int noOfuniqueShoes(long long s[],int size){
    if(size == 1){
        return 1;
    }

    int smallProblem = noOfuniqueShoes(s+1,size-1); // smallerProblem being no of unique 
                                                    // shoes in the smaller array. smaller array : s+1

    // checking if the s[0] is present in the smaller array or not.
    // If present then s[0] is not an unique shoe.
    for(int i=1; i<size; i++){
        if(s[0]==s[i]){
            return smallProblem;
        }
    }
    return smallProblem+1;
}

int main(){
    long long s[4];

    for(int i=0; i<4; i++){
        cin >> s[i];
    }

    cout << (4-noOfuniqueShoes(s,4));

    return 0;
}