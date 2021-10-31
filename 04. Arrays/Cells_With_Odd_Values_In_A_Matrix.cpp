/*
There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.

For each location indices[i], do both of the following:

Increment all the cells on row ri.
Increment all the cells on column ci.
Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.*/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int> > vec( n , vector<int> (m, 0));  
        for(int i=0;i<indices.size();i++){
            int ri = indices[i][0];
            int ci = indices[i][1];
            for(int j=0;j<m;j++){
                vec[ri][j] = vec[ri][j] + 1;
            }
            for(int j=0;j<n;j++){
                vec[j][ci] = vec[j][ci] + 1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]%2!=0){
                    count++;
                }
            }
        }
        return count;
    }
};