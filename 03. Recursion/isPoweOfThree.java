class Solution {
    public boolean isPowerOfThree(int n) {
         if(n<=0) return false;
         if(n==1 ) return true;
        if(n%3==2 || n%2==0 ) return false;
        if(n==2)  return true;
          
        return isPowerOfThree(n/3);
    }
}
