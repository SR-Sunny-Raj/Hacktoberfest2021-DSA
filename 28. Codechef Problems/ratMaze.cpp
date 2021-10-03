// Story: You have to find a path through which the rat move from the starting position (0,0) to the final position where cheese is (n,n). List the total no of possible paths which the rat can take to reach the cheese.

// Input
// A file whose first line contains the size of the square maze The next n lines contain n binary values separated by space. 0 denotes an open cell while 1 denotes a blocked cell. You have to find paths which contain only cells which are open, and finally print the total no of such unique paths. Retracing the 1 or more cells back and forth is not considered a new path. The set of all cells covered in a single path should be unique from other paths

// Output
// The output should be the total no of paths possible on the first line


#include <bits/stdc++.h>
#define vvi vector<vector<int>>
using namespace std;

bool can_we_go(int i, int j, vvi &mat, vvi &vis){
    int n=mat.size();
    return i>=0 and j>=0 and i<n and j<n and mat[i][j]==0 and vis[i][j]==false;
}

int ans=0;

void ratMaze(vvi &mat, int i,int j, vvi &vis){
    int n=mat.size();
    if(i==n-1 & j==n-1){
        ans++;
        return;
    }
    
     vis[i][j]=1;
     //up
     if(can_we_go(i-1,j,mat, vis)==true){
         ratMaze(mat, i-1, j, vis);
     }
     //Left
     if(can_we_go(i,j-1,mat, vis)==true){
         ratMaze(mat, i, j-1, vis);
     }
     //Down
     if(can_we_go(i+1,j,mat, vis)==true){
         ratMaze(mat, i+1, j, vis);
     }
     //right
     if(can_we_go(i,j+1,mat, vis)==true){
         ratMaze(mat, i, j+1, vis);
     }
     vis[i][j]=0;
}



int main(){
    int n;
    cin>>n;
    vvi arr(n, vector<int> (n));
    vvi vis(n, vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    ratMaze(arr, 0, 0, vis);
    cout<<ans<<endl;
    return 0;
}