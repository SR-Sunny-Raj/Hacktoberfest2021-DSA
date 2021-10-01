/*
You are given an array of strings arr. A string s is formed by 
the concatenation of a subsequence of arr that has unique 
characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array 
by deleting some or no elements without changing the order of 
the remaining elements.
 

Example 1:

Input: n=3, arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: n=4, arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: n=1, arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.
Example 4:

Input: n=2, arr = ["aa","bb"]
Output: 0
Explanation: Both strings in arr do not have unique characters, thus there are no valid concatenations.
 

Constraints:

1 <= n <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/

//main driver
#include <bits/stdc++.h>

using namespace std;

map<char,int>ck;
int su=0;
void maxLength(string ar[],int st,int n){
	int tel=0;
	for(int i=int('a');i<=int('z');i++)
		if(ck[char(i)]>1)return;
		else if(ck[char(i)]==1)tel++;
	su=max(tel,su);
	for(int i=st;i<n;i++){
		for(char c:ar[i])ck[c]++;
		maxLength(ar,i+1,n);
		for(char c:ar[i])ck[c]--;
	}
}
int main(){
	int t;
	cin>>t;
	while(t-->0){
		su=0;
		int n;
		cin>>n;
		string ar[n];
		for(int i=0;i<n;i++)cin>>ar[i];
		maxLength(ar,0,n);
		cout<<su<<endl;
	}
}