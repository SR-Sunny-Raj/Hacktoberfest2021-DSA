class Solution{
public:
    string remove(string s){
        // code here
        string res;
        int i=0;
        int n = s.length();
        while(i<n){
            if(s[i] != s[i+1]){
                res.push_back(s[i]);
                i++;
            }
            
            if(i+1<n && s[i] == s[i+1]){
                while(i+1<n && s[i] == s[i+1]){
                    i++;
                }
                i++;
            }
        }
        
        
        return res;
    }
};
