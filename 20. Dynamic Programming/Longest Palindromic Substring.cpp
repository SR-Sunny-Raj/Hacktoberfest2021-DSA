
class Solution{  
string maxStr = "";
public:

    void extendPalindrome(string s, int left, int right){
        string sb = "";
        while(left>=0 && right<=s.size() && s[left] == s[right])
        {
            if(left == right){
                sb += s[left];
            }else{
                string l;
                l += s[left];
                string r ;
                r += s[right];
                sb.insert(0,l);
                sb.insert(sb.size(), r);
            }
            left--;
            right++;
        }
        if(sb.size()>maxStr.size()){
            maxStr = sb;
        }
    }
    
    
    string longestPalindrome(string S){
        for(int i=0;i<S.size();i++){
            extendPalindrome(S,i,i);
            extendPalindrome(S,i,i+1);
        }
        return maxStr;
    }
};

