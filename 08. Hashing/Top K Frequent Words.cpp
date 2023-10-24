/*
Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

bool sortByVal(const pair<string,int> &p1, const pair<string,int> &p2){ 
       return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
} 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<string, int>> vec;
        
        for (auto x:mp){
            vec.push_back(make_pair(x.first, x.second));
        }
        sort(vec.begin(), vec.end(), sortByVal);
        
        vector<string> ans;
        for(int i=0;i<k && i<vec.size();i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();