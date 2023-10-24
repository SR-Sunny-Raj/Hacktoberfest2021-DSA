// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int n,k;
   cin>>n>>k;
        queue<int> q;
        while (n--) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }



// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
  stack<int> s;
  for (int i = 0; i < k; i++)
  {
    int x=q.front();
    q.pop();
    s.push(x);
  }
    
    for (int i = 0; i < k; i++)
    {
        int x=s.top();
        s.pop();
        q.push(x);
    }

    for (int i = 0; i < (q.size()-k); i++)
    {
        int x=q.front();
        q.pop();
        q.push(x);

    }
    
    return q;

}
