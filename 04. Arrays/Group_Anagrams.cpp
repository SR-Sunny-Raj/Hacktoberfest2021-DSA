/*
Problem Statement:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: n=6, strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: n=0, strs = [""]
Output: [[""]]
Example 3:

Input: n=1, strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

//Main Driver
#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& st) {
	int n=st.size();
	map<string,vector<int>>mp;
	for(int i=0;i<n;i++){
		string s=st[i];
		sort(s.begin(),s.end());
		mp[s].push_back(i);
	}
	vector<vector<string>>vc(mp.size());
	int le=-1;
	for(auto j:mp){
		le++;
		for(int i=0;i<j.second.size();i++){
			vc[le].push_back(st[j.second[i]]);
		}
	}
	return vc;
}
int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<string>st(n);
		for(int i=0;i<n;i++)cin>>st[i];
		vector<vector<string>>vc=groupAnagrams(st);
		for(int i=0;i<vc.size();i++){
			for(int j=0;j<vc[i].size();j++)cout<<vc[i][j]<<" ";
			cout<<endl;
		}
	}
}