// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
  
//   Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000




class Solution {
    public double myPow(double x, int n) {
        double ans1 = 1.0;
        long a =n;
        
        if(a<0){
            a = -1*a;
        }
        while(a>0){
            if(a%2==1){
                ans1 = ans1 *x;
                a = a-1;
            }
            
            else{
                x = x*x;
                a = a/2;
            } 
        }
        if(n<0){
            ans1 = 1.0/ans1;
            return ans1;
            
        } return ans1;
    }
    
    
 public void main(String[] args){
        System.out.println(myPow(2,10));
 }
};


