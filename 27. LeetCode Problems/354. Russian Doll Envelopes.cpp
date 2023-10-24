class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        vector<int> arr;
        
        for (int i = 0; i < envelopes.size(); i++) {
            vector<int>::iterator pos = lower_bound(arr.begin(), arr.end(), envelopes[i][1]);            
            int index = pos - arr.begin();
            
            if (pos == arr.end()) {
                arr.push_back(envelopes[i][1]);
            }
            else if(arr[index] > envelopes[i][1]){
                arr[index] = envelopes[i][1];
            }
        }
        
        return arr.size();
    }
};