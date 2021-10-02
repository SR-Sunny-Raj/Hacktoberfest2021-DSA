#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int m = 1;
    for(int i = 0; i < s.length(); i++)
    {
        int c = 1;
        while(s[i] == s[i+1] && (i+1) < s.length())
        {
            ++c;
            ++i;
        }
        m = max(m,c);
    }
    cout<<m<<endl;
}
