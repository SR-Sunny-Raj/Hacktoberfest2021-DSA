/*
Given a stack, sort the elements inside that stack in ascending order using only push and pop operation. You can use one additional stack only.

    For eg.

Input Stack :  5 (top)
               4
               3
               2
               1
Output Stack : 1 (top)
               2
               3
               4
               5

Input format :

Line 1 : No. of elements in stack

Line 2 : Stack elements (separated by space)
Sample Input

5
1 2 3 4 5

Sample Output

1 2 3 4 5

*/

#include <stack>
using namespace std;
void sortStack(stack<int> &s){
	// Write your code here
    stack<int> temp;
    
    while(!s.empty())
    {
        if(temp.empty()){
            temp.push(s.top());
            s.pop();
            continue;
        }
        if(!temp.empty() && temp.top()>=s.top()){
            temp.push(s.top());
            s.pop();
        }
        else{
            int t=s.top();
            s.pop();
            
            while(!temp.empty() && t>temp.top()){
                s.push(temp.top());
                temp.pop();
            }
            temp.push(t);
        }
    }
    s=temp;
}
#include <iostream>
using namespace std;

int main() {
    stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}
