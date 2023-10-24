//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

//Each number in candidates may only be used once in the combination.


class Solution {

   
public:
    
     vector<vector<int>>result;
     void solve(vector<int>& candidates, int target, int sum, vector<int>& temp, int idx){
        if(sum>target)
            return;
    
        if(sum==target){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
                temp.push_back(candidates[i]);
                solve(candidates, target, sum+candidates[i], temp, i+1);
                temp.pop_back();
        }
         return;
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, sum, temp, 0);
        return result;
    }
    
   
    
};
