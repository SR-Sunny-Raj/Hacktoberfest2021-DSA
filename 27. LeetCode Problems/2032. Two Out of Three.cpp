class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         map<int,int>mp1,mp2,mp3;
        
//         for(auto x:nums1) mp1[x]++;
        
//         for(auto x:nums2) mp2[x]++;
        
//         for(auto xLnums3) mp3[x]++;
        map<int,int>mp;
        vector<int>res;
        for(auto x:nums1)
        {
            for(auto y:nums2)
            {
                for(auto z:nums3)
                {
                    if(x==y)
                    {
                        mp[x]++;
                        if(mp[x]==1)
                            res.push_back(x);
                    }
                    
                    if(y==z)
                    {
                        mp[y]++;
                        if(mp[y]==1)
                            res.push_back(y);
                    }
                    
                    if(x==z)
                    {
                        mp[x]++;
                        if(mp[z]==1)
                            res.push_back(x);
                    }
                }
            }
        }
        return res;
        
    }
};