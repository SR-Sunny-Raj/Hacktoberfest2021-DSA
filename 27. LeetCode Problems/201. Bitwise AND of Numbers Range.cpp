class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ma=-1;
        for(int i=0;i<=31;i++)
        {
            if(left==right)
            {
                ma=i;
                break;
            }
                
            left=left>>1;
            right=right>>1;
        }
        left=left<<ma;
        return left;
    }
};