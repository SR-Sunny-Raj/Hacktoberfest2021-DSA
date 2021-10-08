// Given a string str and a pattern pat. 
//You need to check whether pattern is present or not in the given string. 
// Input Format: The input line contains T, denoting the number of testcases. 
//Each testcase contains two lines. First line contains string str. Second line contains patter text.
// Output format: For each testcase in new line you have to print the "Present" 
//if found otherwise "Not present".
/*
Sample Input:
2
abcdefh
bcd
axzy
xy

Sample Output:
Present
Not present
*/

#include <bits/stdc++.h>
using namespace std;


bool searchPattern(string str, string pat)
{
    return str.find(pat)!=-1;
}


int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}