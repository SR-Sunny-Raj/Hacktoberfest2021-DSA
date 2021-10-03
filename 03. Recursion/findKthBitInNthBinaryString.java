class Solution {
    public char findKthBit(int n, int k) {
        if(n==1 && k==1){
            return '0';
        }
        if(k==Math.pow(2,n-1)) return '1';
        else if(k<Math.pow(2,n-1)){
            return findKthBit(n-1, k);
        }else{
            char c=findKthBit(n-1 ,2*(int)Math.pow(2,n-1)-k);
            if(c=='0'){
                return '1';
            }else{
                return '0';
            }
        }
    }
}
