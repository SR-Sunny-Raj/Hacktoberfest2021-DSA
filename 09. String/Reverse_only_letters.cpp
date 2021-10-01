class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low=0,high=s.size()-1,temp,k,r;
        while(low<high)
        {
            k=0;r=0;
            
            if((s[low]>='A' && s[low]<='Z') || (s[low]>='a' && s[low]<='z')) 
                k=1;
            if((s[high]>='A' && s[high]<='Z') || (s[high]>='a' && s[high]<='z')) 
                 r=1;
            
            if(k==1&&r==1)
            {
              temp=s[low];
              s[low]=s[high];
              s[high]=temp;
                low++; high--;                
            }
            else
            {
             if(k==0)low++;
             if(r==0)high--;
            }
            
        }return s;
    }
};
