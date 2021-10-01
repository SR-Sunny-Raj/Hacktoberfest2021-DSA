#define   pb  push_back
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         vector<int> ans ;
         unordered_map<int,int> mp ;
        for ( int i =0 ; i<nums.size(); i++)
        {
            mp[nums[i]] ++ ;
        }
        
        //
        priority_queue<pair<int,int>> pq ;
        for (auto x :mp )
        pq.push(make_pair(x.second ,x.first) ) ;
        
        for ( int i=0 ; i< k ; i++){
            ans.pb(pq.top().second) ;
            pq.pop() ;
        }
        return ans ;
    }
};


//Given a non-empty array of integers, 
//find the top k elements which have the highest frequency in the array.
//If two numbers have the same frequency then the larger number should be given preference. 

