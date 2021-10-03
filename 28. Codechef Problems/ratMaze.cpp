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