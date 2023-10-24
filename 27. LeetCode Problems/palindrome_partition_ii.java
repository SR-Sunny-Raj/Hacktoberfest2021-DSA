//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.

import java.util.*;
class PalindromePartition{
    
    int[] dp;
    public int minCut(String s) {
        dp=new int[s.length()];
        return minCuts(s,0,s.length()-1);
    }
    
    public boolean isPalindrome(String s,int start,int end){
        while(start<end)
        {
            if(s.charAt(start)!=s.charAt(end))
                return false;
            start+=1;
            end-=1;
        }
        return true;
    }
    
    public int minCuts(String s,int start,int end)
    {
        if(start>=end)
            return 0;
        if(isPalindrome(s,start,end))
            return 0;
        if(dp[start]!=0)
            return dp[start];
        int total=Integer.MAX_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i=start;i<=end;i++)
        {
            if(isPalindrome(s,start,i))
                total=1+minCuts(s,i+1,end);
            min=Math.min(min,total);
        }
        dp[start]=min;
        return min;
    }


    //uncomment for input and output
    /*
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        System.out.println(new PalindromePartition().minCut(s));
    }
    */
}