class Solution {
public:
    string maximumNumber(string s, vector<int>& a) {
        int f=0;
        for(int i=0;i<s.size();i++)
        {
            if( (s[i]-'0') < a[s[i]-'0'] ) 
            {
                s[i]=( '0' + a[s[i]-'0']) ;
                f=1;
            }    
            else if( (s[i]-'0') > a[s[i]-'0'] ) 
            {
                if(f==1) return s;
            }
        }
        return s;
    }
};
