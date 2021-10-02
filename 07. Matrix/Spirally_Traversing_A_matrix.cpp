#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
       int rtemp=0,row=r-1,ctemp=0,col=c-1,i;
        vector<int>ans;
        
        while((rtemp<=row)&&(ctemp<=col))
        {
            for(i=ctemp;i<=col;i++)
                ans.push_back(matrix[rtemp][i]);
            for(i=rtemp+1;i<=row;i++)
               ans.push_back(matrix[i][col]);
              
           rtemp++;
            col--;
            if(rtemp<=row)
             for(i=col;i>=ctemp;i--)
                ans.push_back(matrix[row][i]);
            if(ctemp<=col)
            for(i=row-1;i>=rtemp;i--)
               ans.push_back(matrix[i][ctemp]);
            row--;
            ctemp++;
        }
        return ans;

    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends