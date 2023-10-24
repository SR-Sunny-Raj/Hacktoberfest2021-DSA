/*
Mango Trees
Rahul's father ahs left a farm organized as an N x N grid.
Each square in the grid either ahs or does nto have a mango 
tree. He has to divide the frm with his three sisters as follows:
he will draw one horizontal line and one vetical line 
to divide the field into four rectangles. His sisters will
choose three of the four smaller fields and he gets the last one.
Find the maximum number of trees Rahul can get.

INPUT
1
6
.##...
#..##.
.#....
.##..#
#..##.
.#....

OUTPUT
3
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
       int n; cin >> n;
       string s[n];
       for(int i=0; i<n; i++) cin >> s[i];
       int arr[n][n]={s[0][0] == '#'};
       for(int i=1; i<n; i++){
           arr[0][i] = (s[0][i] == '#') + arr[0][i-1];
           arr[i][0] = (s[i][0] == '#') + arr[i-1][0];
       }
       for(int i=1; i<n; i++){
           for(int j=1; j<n; j++){
               arr[i][j] = (s[i][j] == '#') + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
           }
       } 
       int s1,s2,s3,s4;
       int mx = INT_MIN;
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               s1 = arr[i][j];
               s2 = arr[i][n-1] - s1;
               s3 = arr[n-1][j] - s1;
               s4 = arr[n-1][n-1] - s1 - s2 - s3;
               mx = max(mx, min(s1,min(s2,min(s3,s4))));
           }
       }
       cout << mx << '\n';
    }
    return 0;
}