//Program to delete all the vowels present in a string given by the user.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string s2;
    cout << "Enter string: ";
    getline(cin,s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            continue;
        }
        else
        {
            s2.push_back(s[i]);
        }
    }
    cout << s2;
}
