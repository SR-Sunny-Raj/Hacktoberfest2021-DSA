class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //size is the length of the row of mat(also column since it is square matrix)
        int size = mat.size();
        
        //we put the total sum of all the elements in the diagonal in this variable
        int diagonal = 0;
        
        //if size is odd
        if(size%2 != 0){
            //mid is half of size, middle row/column
            int mid = (size)/2;
            for(int i = 0; i< size; i++){
                /* we are adding both principal diagonal elements and 
                  the other diagonal elements through for loop */
                diagonal += mat[i][i] + mat[size-i-1][i];
            }
            /* from above for loop, the element where the diagonals
               intersect has been added twice, so we subtract the duplicate */
            diagonal -= mat[mid][mid];
        } 
        
        // if the size is even
        else{
            for(int i = 0; i< size; i++)
                /* we are adding both principal diagonal elements and 
                  the other diagonal elements through for loop */
                diagonal += mat[i][i] + mat[size-i-1][i];
        } 
        
        // we are returning the solution - sum of diagonals
        return diagonal;
    }
};
