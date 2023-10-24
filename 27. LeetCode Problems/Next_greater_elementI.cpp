/*
    Problem link
    https://leetcode.com/problems/next-greater-element-i/
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map <int, int> m;
        stack <int> st;
        for(int j=nums2.size()-1; j>=0; j--){
            while(st.size()>0 && st.top()<=nums2[j]){
                    st.pop();
                }
                if(st.size()==0) {m[nums2[j]]=-1;}
                else m[nums2[j]]=st.top();
            if(st.size()>0 && st.top()>nums2[j]){
                m[nums2[j]]=st.top();
            }
            st.push(nums2[j]);}
        for(int i=0; i<nums1.size(); i++){
            int x=m[nums1[i]];
            nums1[i]=x;
        }
        return nums1;
    }
};