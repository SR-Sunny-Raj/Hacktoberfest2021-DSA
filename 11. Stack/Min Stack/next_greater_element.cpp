
// Write your code here
#include<bits/stdc++.h>
#include<iostream>
using  namespace std;
""" 
finding next greater element of vector using stack
LOGIC:
we push the elements onto the stack ,popping the elements 
which are smaller than or equal to current element
and assigning the NGE of popped elements the index of current element ,then 
push the current element onto the stack.

"""
vector<int> NGE(vector<int> &num)
{   stack<int> s;
int n=num.size();
vector<int> res(n);
	for(int i=0;i<n;i++)
	{
		while((!s.empty())&&(num[s.top()]<=num[i]))
		{
			res[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
	{
		res[s.top()]=-1;
		s.pop();
	}

	
	return res;
}
int main()
{
int n;
cin>>n;
vector<int> num(n);
for(int i=0;i<n;i++)
cin>>num[i];

// eg. given vector is 5  2  7  10  9
// the NGE vector is   2  2  3  -1  -1  here the NGE vector stores the indexes

// stores the index of next greater element, if no such element exists writes -1 it its position 

vector<int> nge=NGE(num);
for(int val: nge)
cout<<val<<" ";
}

