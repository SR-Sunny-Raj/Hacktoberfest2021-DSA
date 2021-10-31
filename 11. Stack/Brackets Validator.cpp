#include <bits/stdc++.h>
using namespace std;
char st[100];
int top=-1;
void push(int t) {
	if(top==99) {
		cout<<"Full";
		return ;
	}
	st[++top]=t;
}
char pop() {
	if(top==-1) {
		return 'z';
	}
	return st[top--];
}

int main()
{
	char a[100],t;
	bool flag=0;
	cout<<"Enter\n";
	cin>>a;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i] == '{' || a[i] == '(' || a[i] == '[') {
			push(a[i]);
			
		}
		else {
			t = pop();
			if(t=='z') {
				flag=1;
				break;
			}
			else if(a[i] == '}' && (t == '(' || t == '[')) {
				flag=1;
				break;
			}
			else if(a[i] == ')' && (t == '{' || t == '[')) {
				flag=1;
				break;
			}
			else if(a[i] == ']' && (t == '{' || t == '[')) {
				flag=1;
				break;
			}		
		}
	}
	if(top != -1)
	flag=1;
	
	if(flag == 1)
	cout<<"NOt balanced\n";
	else
	cout<<"Balanced\n";
	return 0;
}
