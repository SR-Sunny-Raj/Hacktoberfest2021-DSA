/* Problem :

Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.

Input Format :
String S
Output Format :
count of palindrome substrings

Constraints :
1 <= Length of S <= 1000

Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

//Solution : 

#include<bits/stdc++.h>
using namespace std;

int length(char input[])
{
	int len = 0;
	for(int i=0;input[i]!='\0';i++)
		len++;
	
	return len;
}

int countPalindromeSubstrings(char s[])
{
	int count = 0;
	int len = length(s);
	for(int i=0;i<len;i++)
	{
		int left = i-1;
		int right = i+1;
		count++;
		
		while(left >= 0 && right < len)
		{
			if(s[left] == s[right])
			{
				count++;
				left--;
				right++;
			}
			else
			{
				break;
			}
		}
		
		if(i < len-1 && s[i] == s[i+1])
		{
			left = i-1;
			right = i+2;
			count++;
			while(left >=0 && right < len)
			{
				if(s[left] == s[right])
				{
					count++;
					left--;
					right++;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	return count;
}
int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}