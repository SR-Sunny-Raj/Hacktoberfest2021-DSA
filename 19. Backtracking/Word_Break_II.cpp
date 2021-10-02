class Solution {
public:
     
    bool isValid(string t, vector<string>& wordDict){
        for(int i=0; i<wordDict.size(); i++){
            if(t.compare(wordDict[i]) == 0){
                return true;
            }
        }
        return false;
    }
    
    void solve(int idx, string &s, string &t, string &T, vector<string> &wordDict, vector<string> &ans){

        if(idx > s.size()){
            return;
        }

        if(idx == s.size()){
            ans.push_back(T);
            return;
        }

        for(int i= idx; i<s.size(); i++){
            t += s[i];
            bool mila_kya = isValid(t,wordDict);

            
            if(mila_kya == true){
                string x = T, y = t;
                T += t;
                if(i != s.size()-1){
                    T += ' ';
                }
                t = "";
                solve(i+1,s,t,T,wordDict,ans);
                t = y;
                if(i != s.size()-1){
                    T.pop_back();
                } //T -= ' ';
                T = x;
            }
        }

    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string T = "", t = "";
        
        solve(0,s,t,T,wordDict,ans);
        return ans;
    }
};
