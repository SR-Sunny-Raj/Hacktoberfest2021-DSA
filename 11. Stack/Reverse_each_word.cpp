#include <bits/stdc++.h>
using namespace std;

                                                    // reverses individual words of a string
void reverseWords(string A)
{
    stack<char> s;
                                                   //push all character till space.
    for (int i = 0; i < A.size();i++) {
        if (A[i] != ' ')
            s.push(A[i]);

                                                    // we print  stack.
        else {
            while (s.empty() == false) {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
}


    while (s.empty() == false) {
        cout << s.top();
        s.pop();
    }
}

                                                      // Driver program to test function
int main()
{
    string s = "Spread love everywhere you go";
    reverseWords(s);
    return 0;
}
