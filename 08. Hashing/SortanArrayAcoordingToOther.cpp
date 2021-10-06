//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
    {
        //Your code here
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<N;i++)
            m[A1[i]]++;
        for(int i=0;i<M;i++)
        {
            if(m.find(A2[i])!=m.end())
            {
                while(m[A2[i]]--)
                    v.push_back(A2[i]);
                m.erase(A2[i]);
            }
        }
        for(auto i:m)
        {
            while(i.second--)
                v.push_back(i.first);
            m.erase(i.first);
        }
        return v;
    }
};

// { Driver Code Starts.

int main(int argc, char *argv[])
{

	int t;

	cin >> t;

	while(t--){

	    int n, m;
	    cin >> n >> m;

	    vector<int> a1(n);
	    vector<int> a2(m);

	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }

	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m);


	    for (int i = 0; i < n; i++)
		    cout<<a1[i]<<" ";

	    cout << endl;


	}
	return 0;
}
  // } Driver Code Ends
