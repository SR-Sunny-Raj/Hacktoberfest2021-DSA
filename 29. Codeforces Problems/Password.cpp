///O(n+m)
/*
   B. Password
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Asterix, Obelix and their temporary buddies Suffix and Prefix has finally found the Harmony temple. However, its doors were firmly locked and even Obelix had no luck opening them.

A little later they found a string s, carved on a rock below the temple's gates. Asterix supposed that that's the password that opens the temple and read the string aloud. However, nothing happened. Then Asterix supposed that a password is some substring t of the string s.

Prefix supposed that the substring t is the beginning of the string s; Suffix supposed that the substring t should be the end of the string s; and Obelix supposed that t should be located somewhere inside the string s, that is, t is neither its beginning, nor its end.

Asterix chose the substring t so as to please all his companions. Besides, from all acceptable variants Asterix chose the longest one (as Asterix loves long strings). When Asterix read the substring t aloud, the temple doors opened.

You know the string s. Find the substring t or determine that such substring does not exist and all that's been written above is just a nice legend.

Input
You are given the string s whose length can vary from 1 to 106 (inclusive), consisting of small Latin letters.

Output
Print the string t. If a suitable t string does not exist, then print "Just a legend" without the quotes.

Examples
inputCopy
fixprefixsuffix
outputCopy
fix
inputCopy
abcdabc
outputCopy
Just a legend

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>z_function(string s)
{
    int n = s.size();
    vector<int>z(n);
    for(int i=0; i<n; i++)
    {
        z[i]=0;
    }
    for(int i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i<=r)
        {


            z[i] = min((r-i+1), z[i-l]);

        }


        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        {

            z[i]++;

        }

        if(i+z[i]-1>r)
        {
            l = i;
            r = i + z[i] - 1;
        }

    }
    return z;

}



int main()
{
    string T;
    cin>>T;

    int p=-1;
    vector<int>z= z_function(T);
    vector<int>vec,v;

    for(int i=0; i<T.size(); i++)
    {




        v.push_back(z[i]);

    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=0; i--)
    {
        if(i+z[i]==T.size())
        {


            int l=lower_bound(v.begin(),v.end(),z[i])-v.begin();
            if(T.size()-l>1)
            {

                p=max(p,z[i]);

            }
        }






    }
    if(p==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        for(int i=0; i<p; i++)
        {
            cout<<T[i];
        }
    }

    return 0;
}
