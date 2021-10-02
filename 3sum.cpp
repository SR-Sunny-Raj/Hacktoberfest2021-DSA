class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0 ; i < nums.size(); i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                else if (sum > 0) r--;
                else l++;



            }
        }
        for (auto it : s) ans.push_back(it);

        // if(ans.size() == 0) return {};

        return ans;
    }
};