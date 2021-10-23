/*Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

Example 1:
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701

*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i,ordinal_value,sum=0,n,k=1;
        n=columnTitle.length();
        
        for(i=0;i<n;i++){
        ordinal_value=int(columnTitle[i])- 64;
        sum=sum+(pow(26,n-k)*ordinal_value);
        k++;
        }
        return(sum);
    }
};