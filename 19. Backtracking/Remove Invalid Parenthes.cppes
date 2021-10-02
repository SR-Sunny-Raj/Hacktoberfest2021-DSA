class Solution {
public:
    
    int find_min_removal(string s){
        stack<char> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    st.push(s[i]);
                }
                else{
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        st.push(s[i]);
                    } 
                }
            }
            else{
                continue;
            }
        }
        
        return st.size();
        
    }

    void solve(int min_removal, string s, vector<string> &ans,unordered_map<string,int> &mpp){
        
        if(mpp[s]==1){ // Avoid duplicacy
            return;
        }
        
        mpp[s] = 1; //Add to the map
        if(min_removal==0){
            if(find_min_removal(s)==0){ //check for valid paranthesis
                ans.push_back(s);
            }
            return;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i]!='(' and s[i]!=')'){    //if s[i] is a letter
                continue;
            }
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string temp = left + right;
            solve(min_removal-1,temp,ans,mpp);
        }
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_map<string,int> mpp;
        
        int min_removal = find_min_removal(s);

        solve(min_removal,s,ans,mpp);
     
        return ans;
    }
};
