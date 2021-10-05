class Solution {
public:
    string numberToWords(int n) 
    {
     if(n==0)
         return("Zero");
      
    string v[]={"","Billion","Million","Thousand"};
      
    string s[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen", "Sixteen","Seventeen", "Eighteen","Nineteen"};
      
    string h[]={"","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    if(n<20)
        return(s[n]);
    int m=1000000000,r,t=0;
        string a="";
        for(int i=n;i>0;i%=m,m/=1000)
        {
            r=i/m;
            while(r==0)
                i%=m, m/=1000, r=i/m, ++t;
          
            if(r>99)
                a+=(s[r/100]+" Hundred ");
          
            r=r%100;
          
            if(r>0&&r<20)  
               a+=(s[r]+" ");	
            else if(r%10==0 && r!=0)
              a+=(h[r/10-1]+" ");
            else if(r>19&&r<100)
                a+=(h[r/10-1]+" "+s[r%10]+" ");
          
            if(t<3)
                a+=(v[++t]+" ");
        }
        return(a.substr(0,a.size()-1));
    }
};
