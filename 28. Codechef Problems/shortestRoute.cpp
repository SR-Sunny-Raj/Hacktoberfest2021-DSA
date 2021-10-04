/*

CODECHEF PROBLEM:-
PROBLEM CODE: SHROUTE
LINK: https://www.codechef.com/JUNE21C/problems/SHROUTE

INPUT:
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains three lines of input.
The first line contains two integers N, M.
The second line contains N integers A1,A2,…,AN.
The third line contains M integers B1,B2,…,BM.

OUTPUT:
For each test case, output M space-separated integers C1,C2,…,CM, 
where Ci is the minimum time required by the i-th traveller to reach his destination,
if the i-th traveller can't reach his destination, Ci=−1.

SAMPLE OUTPUT:
3
5 1
1 0 0 0 0
5
5 1
1 0 0 0 2
4
5 2
2 0 0 0 1
3 1

*/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long int t;
	cin >> t;
	while(t--)
	{
	    long int n,m;
	    cin >> n >> m;
	    long int a[n];
	    long int b[m];
	    long int two = -1;
	    long int one = -1;
	    long int c = 0;
	    for (int i=0;i<n;i++)
	    {
	        cin >> a[i];
	        if (a[i]==2)
	        {
	            two = i;
	        }
	    }
	    for (int i=0;i<n;i++)
	    {
	        if (a[i]==1)
	        {
	            one = i;
	            break;
	        }
	    }
	    for(int i=0;i<m;i++)
	    {
	        cin >> b[i];
	    }
	    int *copy1{ new int[n]{} };
	    int *copy2{ new int[n]{} };
	    //int *copy1 = new int[n-1]();
	    //int *copy2 = new int[n-1]();
	    if (one != -1)
	    {
	       for(int i=one;i<n;i++)
	        {
	            if (a[i] == 0)
	            {
	                c++;
	                copy1[i] = c;
	            }
	            if (a[i] == 1)
	            {
	                c=0;
	                copy1[i] = -1;
	            }
	            if (a[i] == 2)
	            {
	                c++;
	                copy1[i] = -1;
	            }
	        } 
	    }
	    if (two != -1)
	    {
	       for(int i=two;i>=0;i--)
	        {
	            if (a[i] == 0)
	            {
	                c++;
	                copy2[i] = c;
	            }
	            if (a[i] == 2)
	            {   
	                c=0;
	                copy2[i] = -1;
	            }
	            if (a[i] == 1)
	            {
	                c++;
	                copy2[i] = -1;
	            }
	        } 
	    }
	    
	    for (int i=0;i<n;i++)
	    {
	        if (copy1[i]==0)
	        {
	            copy1[i]=INT_MAX;
	        }
	        if (copy2[i]==0)
	        {
	            copy2[i]=INT_MAX;
	        }
	        if (copy1[i]==-1)
	        {
	            copy1[i]=0;
	        }
	        if (copy2[i]==-1)
	        {
	            copy2[i]=0;
	        }
	    }
	    for(int i=0;i<m;i++)
	    {
	        long int x = int(b[i]);
	        if (a[x-1] != 0 || b[i] == 1)
	        {
	            cout << 0 << " ";
	        }
	        else
	        {
	            long int ans = min(copy1[x-1],copy2[x-1]);
	            if (ans == INT_MAX)
	            {
	                cout << "-1 ";
	            }
	            else
	            {
	                cout << ans << " ";
	            }
	        }
	    }
	    cout << "\n";
	    
	    
	}
	return 0;
}
