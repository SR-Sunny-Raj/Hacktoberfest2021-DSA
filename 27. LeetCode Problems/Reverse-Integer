// Problem Link: https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        if(x==0)
            return 0;
        long int a = abs(x);
        while(a%10==0)
            a /= 10;
        long int ans = 0;
        while(a>0)
        {
            long int temp = a%10;
            if((ans*10)+temp>pow(2, 31))
                return 0;
            ans = (ans*10)+temp;
            a = (a-temp)/10;
        }
        return x<0?-ans:ans;
    }
};
