/*
input - nums = [1,2,3,4], k = 5
Output: 2
Explanation:
nums = [1,2,3,4]:
2+3 = 5
1+4 = 5
There are no more pairs that sum up to 5, hence a total of 2 operations.
*/


#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> m;
        
        
        for(int i=0; i<nums.size(); i++)
        {
            if(m[k-nums[i]] > 0)
            {
                m[k-nums[i]]--;
                count++;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        return count;
        
    }
int main()
{
  vector<int> v = {1, 2, 3 ,4};
  int k = 5;
  cout << maxOperations(v, k);
  return 0;  
}
