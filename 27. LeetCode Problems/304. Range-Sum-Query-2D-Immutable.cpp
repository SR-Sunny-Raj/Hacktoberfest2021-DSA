// //RANGE SUM QUERY 2D IMMUTABLE 

// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

//CODE
class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(matrix.empty())
            return ;
        int n = matrix[0].size();
        v = vector<vector<int>> (m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    v[i][j] = matrix[0][0];
                } else if(i == 0) {
                    v[i][j] = v[i][j-1] + matrix[i][j];
                } else if(j == 0) {
                    v[i][j] = v[i-1][j] + matrix[i][j];
                } else {
                    v[i][j] = v[i-1][j] + v[i][j-1] + matrix[i][j] - v[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) {
            return v[row2][col2];
        } else if(row1 == 0) {
            return v[row2][col2] - v[row2][col1-1];
        } else if(col1 == 0) {
            return v[row2][col2] - v[row1-1][col2];
        } else {
            return v[row2][col2] - v[row1-1][col2] - v[row2][col1-1] + v[row1-1][col1-1];
        }
    }
};