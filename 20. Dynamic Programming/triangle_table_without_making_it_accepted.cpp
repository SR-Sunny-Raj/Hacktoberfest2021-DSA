class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //now lets see dp table without actually creating it 
        //in recursive solution we got tle at tc 42/44
        //in memoized solution we got tle at tc 43/44
        int n = triangle.size();
        int m = triangle[n-1].size();
        for(int i=n-2;i>=0;i--){
            m = triangle[i].size();
            for(int j =0;j<m;j++){
                triangle[i][j] = triangle[i][j]+ min(triangle[i+1][j+1],triangle[i+1][j]);
            }
        }
        return triangle[0][0];
    }
};