#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin,s);
    int n=s.length();
    string s1="";
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        c++;
    }
    vector<string>arr(c+1);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='1' && s[i]<='9')
        {
            arr[(s[i]-'0')-1]=s1;
            s1="";
        }
        else if(s[i]!=' ')
        {
            s1=s1+s[i];
        }
    }
    for(int i=0;i<c+1;i++)
    cout<<arr[i]<<" ";
    return 0;
}

/*
INPUT:
sentence4 a3 is2 This1

OUTPUT:
This is a sentence
*/
