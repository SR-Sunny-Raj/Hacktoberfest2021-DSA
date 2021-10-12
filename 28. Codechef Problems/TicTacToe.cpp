// Problem link : https://www.codechef.com/MAY21C/problems/TCTCTOE

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int findCondn(string s1,string s2,string s3){

    int wx = 0;
    int wo = 0;
    int cx = 0;
    int co = 0;
    int ce = 0;

    if((s1[0] == s2[0]) && (s1[0] == s3[0]) && (s2[0] == s3[0])){
        if(s1[0] == 'X') wx++;
        if(s1[0] == 'O') wo++;
    }

    if((s1[1] == s2[1]) && (s1[1] == s3[1]) && (s2[1] == s3[1])){
        if(s1[1] == 'X') wx++;
        if(s1[1] == 'O') wo++;
    }

    if((s1[2] == s2[2]) && (s1[2] == s3[2]) && (s2[2] == s3[2])){
        if(s1[2] == 'X') wx++;
        if(s1[2] == 'O') wo++;
    }

    if((s1[0] == s1[1]) && (s1[0] == s1[2]) && (s1[2] == s1[1])){
        if(s1[0] == 'X') wx++;
        if(s1[0] == 'O') wo++;
    }

    if((s2[0] == s2[1]) && (s2[0] == s2[2]) && (s2[2] == s2[1])){
        if(s2[0] == 'X') wx++;
        if(s2[0] == 'O') wo++;
    }

    if((s3[0] == s3[1]) && (s3[0] == s3[2]) && (s3[2] == s3[1])){
        if(s3[0] == 'X') wx++;
        if(s3[0] == 'O') wo++;
    }

    if((s1[0] == s2[1]) && (s1[0] == s3[2]) && (s2[1] == s3[2])){
        if(s1[0] == 'X') wx++;
        if(s1[0] == 'O') wo++;
    }

    if((s1[2] == s2[1]) && (s1[2] == s3[0]) && (s2[1] == s3[0])){
        if(s1[2] == 'X') wx++;
        if(s1[2] == 'O') wo++;
    }

    for(int i = 0 ; i < 3 ; i++){
        if(s1[i] == 'X'){
            cx++;
        }

        if(s1[i] == '_'){
            ce++;
        }

        if(s1[i] == 'O'){
            co++;
        }

        if(s2[i] == 'X'){
            cx++;
        }

        if(s2[i] == '_'){
            ce++;
        }

        if(s2[i] == 'O'){
            co++;
        }

        if(s3[i] == 'X'){
            cx++;
        }

        if(s3[i] == '_'){
            ce++;
        }

        if(s3[i] == 'O'){
            co++;
        }        
    }

    if((wx >= 1 && wo >= 1) || ((cx - co) < 0) || ((cx-co > 1))){
        return 3;
    }
    else if(cx == 0 || co == 0 || ce == 9){
        return 2;
    }
    else if(wx >= 1 && wo == 0 && (cx-co) == 1){
        return 1;
    }
    else if(wx == 0 && wo == 1 && cx == co){
        return 1;
    }
    else if(wx == 0 && wo == 0 && ce == 0){
        return 1;
    }
    else if(wx == 0 && wo == 0 && ce > 0){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--){

        string s1,s2,s3;
        cin>>s1>>s2>>s3;

        cout<<findCondn(s1,s2,s3)<<"\n";
    }
    
    return 0;
}