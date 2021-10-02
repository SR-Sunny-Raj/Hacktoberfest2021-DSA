/*

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/

//solution

class Solution {
    public boolean repeatedSubstringPattern(String s) {
        
        int k = 2;
        while(s.length()/k > 0){
            if(s.length()%k != 0){
                k++;
                continue;
            }
            else{
                int jump = s.length()/k;
                String str = s.substring(0,jump);
                System.out.println(s + " " +str);
                int flag = 0;
                for(int i=jump;i<s.length();i+=jump){
                    System.out.println(str + " " + s.substring(i,i+jump));
                    if(s.substring(i,i+jump).equals(str)){
                        flag++;
                    }
                    else{
                        k++;
                        break;
                    }
                }
                if(flag == k-1){
                    return true;
                }
                System.out.println("flag: " + flag);
            }
        }
        
        return false;
}
}
