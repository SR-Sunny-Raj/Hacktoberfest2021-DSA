class Solution {
public:
    void solve(int index, vector<int>& ds, vector<int>& a, int target, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<a.size();i++){
            if(i>index&&a[i]==a[i-1]){
                continue;
            }
            if(a[i]>target){
                break;
            }
            ds.push_back(a[i]);
            solve(i+1,ds,a,target-a[i],ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(a.begin(),a.end());
        solve(0,ds,a,target,ans);
        return ans;
    }
};