class Solution {
public:
   map<string, vector<string>> m;

    vector<string> fun(string s, vector<string>& wordDict){
        if(s.empty())
            return {""};
        if(m.find(s)!=m.end())
            return m[s];
        vector<string>whole, subpart;
        for(string word : wordDict){
            string t = s.substr(0,word.length());

            if(t != word)
                continue ; 
            else{
                subpart = fun(s.substr(word.length()) , wordDict);
            }

            for(string ans : subpart){
                string delim= ans.length()==0 ? "" : " ";
                whole.push_back(word+delim+ans);
            }
        }

        return m[s] = whole;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
             m.clear();
            return  fun(s,wordDict);
    }
};
