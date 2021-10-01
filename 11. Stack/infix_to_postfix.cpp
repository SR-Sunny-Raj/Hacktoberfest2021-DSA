#include<bits/stdc++.h>
using namespace std;

//function to return precedence of operators
int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

//required function
void infixToPostfix(string s) {

	stack<char> st;
	string result;
//According to convention of stack implentation of infix to postfix expression, conditions are checked.
	for(int i = 0; i < s.length(); i++) {
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;
		else if(c == '(')
			st.push('(');
		else if(c == ')') {
			while(st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while(!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty()) {
		result += st.top();
		st.pop();
	}
//Printing the result
	cout << result << endl;
}

int main() {
	string exp;
    cin>>exp;
	infixToPostfix(exp);
	return 0;
}
