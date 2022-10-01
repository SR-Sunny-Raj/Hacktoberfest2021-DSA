#include<iostream>
using namespace std;

int squareRoot(int n){
    int s=0;
    int e=n;
    int m=s+(e-s)/2;
    int ans=-1;
    
    while(s<=e){
        int square=m*m;
        if(square==n)
        {
            return m;
        }
        if(square<n)
        {
            ans=m;
            s=m+1;
        }
        else
        {
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int x=36;
    cout<< squareRoot(x) << endl;
    return 0;
}