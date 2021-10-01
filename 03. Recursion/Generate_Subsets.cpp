#include<iostream>
using namespace std;
void subsets(string s,string curr="",int i=0)
{
	if(i==s.length())
	{
		cout<<curr<<" ";
		return;
	}
	subsets(s,curr,i+1);
	subsets(s,curr+s[i],i+1);
}
int main()
{
	string s,curr;
	cout<<"Enter a string ";
	cin>>s;
	cout<<"The subsets of the above string are ";
	subsets(s,curr,0);
	return 0;
}
