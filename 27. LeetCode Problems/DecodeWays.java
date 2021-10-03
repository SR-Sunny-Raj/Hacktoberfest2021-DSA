//Leetcode problem 91. Decode Ways
//Given a string s containing only digits, return the number of ways to decode it.
// For more details check leetcode


class Solution {

    //This solution uses a recursive DP/memoization based approach instead of an iterative one
    int dp[];
    public int numDecodings(String s) {
        int len=s.length();
        dp=new int[len+1];
        Arrays.fill(dp,-1);
        return decodeWays(s,0,len);
    }
    
    int decodeWays(String s, int start, int len) {
        if (start >= len)
            return 1;
        if (dp[start] != -1)
            return dp[start];

        int total = 0;
        //Idea is take both possibilites- 1 char as a decoding and 2 chars as a decoding
        if(start+1<=len)
        {
            String single=s.substring(start,start+1);
            if(isValid(single))
                total+=decodeWays(s, start+1, len);
        }

        if(start+2 <=len){
            String pair=s.substring(start,start+2);
            if(isValid(pair))
                total+=decodeWays(s, start+2, len);
        }
        dp[start] = total;
        return total;
    }

    boolean isValid(String s) {
        if (s.length() == 0 || s.startsWith("0"))
            return false;
        int value = Integer.parseInt(s);
        return (value >= 1 && value <= 26);
    }
}