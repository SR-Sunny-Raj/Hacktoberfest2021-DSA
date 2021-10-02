#include <bits/stdc++.h>
using namespace std;

    int isValid(string s) {

            int n=s.length();
            int i,j,numLen=0;
            int pre=-1,number=0,count=0;
            for(i=0;i<n;i++)
            {
                int temp=s[i];
                
                if((temp<48 || temp>57) && s[i]!='.' )
                    return 0;
                
                if(s[i]=='.')
                {
                    if(i-pre>4 || i-pre==1 || i==0)
                        return 0;
                    else
                        pre=i;
                    count++;
                    if(number==0 && numLen>1)
                        return 0;
                    number=0;
                    numLen=0;
                }
                else
                {
                    numLen++;
                    number=(number*10)+s[i]-48;
                }
                
                if(number>=0 && number<10 && numLen>1)
                    return 0;
                if(number>=10 && number<99 && numLen>2)
                    return 0;
                if(number>=100 && number<256 && numLen>3)
                    return 0;
                
                if(number>255)
                    return 0;
            }
            
                    
            if(count==3 && s[n-1]!='.')
                return 1;
            return 0;
        }

int main() {

        string s;
        cout<<"Enter IP address to check validity" << endl;
        cin >> s;
        int result=isValid(s);
        if(result==1)
        cout << "The IP address is valid.";
        else
        cout<< "The IP address is invalid.";
    return 0;
}//main