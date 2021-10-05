/*
Problem Link: https://www.codechef.com/LTIME91B/problems/SWAP10HG
*/





#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int one1=count(s1.begin(),s1.end(),'1');

        int zero1=count(s1.begin(),s1.end(),'0');
        int one2=count(s2.begin(),s2.end(),'1');

        int zero2=count(s2.begin(),s2.end(),'0');
        int p=1,cnt=0;
        if(one1==one2 && zero1==zero2)
        {
            // cout<<"*"<<endl;
            for(int i=0; i<n; i++)
            {
                if(s1[i]!=s2[i])
                {
                    if(s1[i]=='0')
                    {
                        cnt--;
                        if(cnt<0)
                        {
                            p=0;
                            break;
                        }
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
        }
        else
        {
            p=0;
        }
        if(p==0)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }

    }
}
