#include <bits/stdc++.h>

using namespace std;

string Country_at_war(int a[], int b[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+1], b[n+1];

        for(int i=0;i<n;i++)
            cin>> a[i];
        
        for(int i=0;i<n;i++)
            cin>> b[i];

        cout << Country_at_war(a, b, n) << endl;

    }
    return 0;
}
// } Driver Code Ends


string Country_at_war(int a[], int b[], int n)
{
    // Complete the function
    int A=0,B=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
          {   A++;
            
          } 
        else if(b[i]>a[i])
             B++;
            
    }  
            
        if(A>B)
            return "A";
        else if(B>A) 
            return "B";
        else if(A==B)
            return "DRAW";
        
    
}
