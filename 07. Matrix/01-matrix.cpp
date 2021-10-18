class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size(), cols = mat[0].size();
    
        vector <vector<int>> distMat(rows, vector <int> (cols, INT_MAX - 100000));
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][j] == 0) {
                    distMat[i][j] = 0;
                    continue;
                }
                distMat[i][j] = !(i > 0) ? distMat[i][j] : min(distMat[i][j], distMat[i-1][j] + 1);
                distMat[i][j] = !(j > 0) ? distMat[i][j] : min(distMat[i][j], distMat[i][j-1] + 1);
            }
        }
        
        for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {
                distMat[i][j] = !(i < rows - 1) ? distMat[i][j] : min(distMat[i][j], distMat[i+1][j] + 1);
                distMat[i][j] = !(j < cols - 1) ? distMat[i][j] : min(distMat[i][j], distMat[i][j+1] + 1);
            }
        }
        
        return distMat;
    }
};
