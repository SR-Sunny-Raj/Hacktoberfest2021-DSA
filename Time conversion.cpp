# include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a =(int)s[0] - 48;
    int b =(int)s[1] - 48;
    int c = 10*a+b;
    c+=12;
    if(c>=24){
        c=c%24;
    }
    int d = c/10;
    int e =c%10;

    char f = (char)(48+d);
    char g = (char)(48 + e);
    cout<<f<<g;
    for(int i=2;i<s.size()-2;i++){
        cout<<s[i];
    } 
    return 0;
}
