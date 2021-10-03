#include<iostream>
#include<string>
using namespace std;

bool isSubSeq(string &s1, string &s2, int m, int n)
{
    if (m == 0)
		return true;
	if (n == 0)
		return false;
	if (s1[m-1] == s2[n-1])
		return isSubSeq(s1,s2, m - 1, n - 1);
	return isSubSeq(s1, s2, m, n - 1);
}
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    if(isSubSeq(s1,s2,m,n))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}