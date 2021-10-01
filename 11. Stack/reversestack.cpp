// given an array and a astack contains all the elemnts of it reverse the stack and print the original array

/* You have been given two stacks that can store integers as the data.
Out of the two given stacks, one is populated and the other one is empty. 
You are required to write a function that reverses the populated stack using the one which is empty.*/


#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.size()==0||input.size()==1)
    {
        return;
    }
    int x=input.top();
    input.pop();
   reverseStack(input,extra);
int size1 = input.size();
for(int i=0;i<size1;i++)
{
    extra.push(input.top());
    input.pop();
}
input.push(x);
int size2 = extra.size();
for(int i=0;i<size2;i++)
{
    input.push(extra.top());
    extra.pop();
}
    
}
int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
