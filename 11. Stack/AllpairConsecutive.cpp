#include <bits/stdc++.h>
using namespace std;
 
                                                    // check if elements are consecutive pair in stack
bool AllpairConsecutive(stack<int> s)
{
                                                    // store elements of s to a.
    stack<int> a;
    while (!s.empty()) {
        a.push(s.top());
        s.pop();
    }                                               //check for consecutive pair
    bool result = true;
    while (a.size() > 1) {
                                                    //get top elsement
        int A = a.top();
        a.pop();
        int B = a.top();
        a.pop();
        
        if (abs(A - B) != 1)
          result = false;
 
                                                   // Push elements to original stack.
        s.push(A);
        s.push(B);
    }
 
    if (a.size() == 1)
        s.push(a.top());
 
    return result;
}
 
                                                   // Driver program
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(-1);
    s.push(-2);
    s.push(10);
    s.push(9);
    
    cout << "Stack elements from top\n";
    while (s.empty() == false)
    {
       cout << s.top() << " ";
       s.pop();
    }
    if (AllpairConsecutive(s))
        cout << "\nYes" << endl;
    else
        cout << "\nNo" << endl;

    return 0;
}
