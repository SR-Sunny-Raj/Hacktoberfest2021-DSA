// Repeated DNA Sequences
// have to return all substrings from given string that consists of 10 letters 
// and occurs more than once in the given string


// INPUT - 1
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]

// INPUT - 2
// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]

#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> mp;
    vector<string> result;
    int i=0,j=0,k=10;
    string res;
    while(j < s.length()){
        res += s[j];
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            mp[res]++;
            res.erase(res.begin(), res.begin()+1);
            i++;
            j++;
        }
    }
    for(auto it: mp){
        if(it.second > 1)
            result.push_back(it.first);
    }
    return result;
}

int main(){

    string str;
    vector<string> res;
    cout << "Enter String: ";
    cin >> str;

    res = findRepeatedDnaSequences(str);
    for(auto it: res){
        cout << it << " ";
    }
}