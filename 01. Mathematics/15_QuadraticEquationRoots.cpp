// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> quadraticRoots(int a, int b, int c)
    {
        vector<int> ans;
        if(a==0)
        {
            ans.push_back(-1);
            return ans;
        }
        int d = b*b - 4*a*c;
        double sqrt_val = sqrt(abs(d));
        if(d>0)
        {
            double root1 = (double)(-b + sqrt_val)/(2*a);
            double root2 = (double)(-b - sqrt_val)/(2*a);
            ans.push_back(root1);
            ans.push_back(root2);
        }
        else if(d==0)
        {
            double root = -(double)b/(2*a);
            ans.push_back(root);
            ans.push_back(root);
        }
        else
        {
            ans.push_back(-1);
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++)
                cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
