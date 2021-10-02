
// In the Byteland country, a string S is said to super ASCII string if and only if the count of each character in the string is equal to its ASCII value. In the Byteland country ASCII code of ‘a’ is 1, ‘b’ is 2, …, ‘z’ is 26. The task is to find out whether the given string is a super ASCII string or not. If true, then print “Yes” otherwise print “No”.

// Examples:

// Input: S = “bba” 
// Output: Yes
// Explanation:
// The count of character ‘b’ is 2 and the ASCII value of ‘b’ is also 2.
// The count of character ‘a’ is 1. and the ASCII value of ‘a’ is also 1. 
// Hence, string “bba” is super ASCII String.

// Input: S = “ssba”
// Output: No
// Explanation:
// The count of character ‘s’ is 2 and the ASCII value of ‘s’ is 19.
// The count of character ‘b’ is 1. and the ASCII value of ‘b’ is 2.
// Hence, string “ssba” is not a super ASCII String.




#include<stdio.h>

#include<string.h>

int main()
{
    int t;

    
    scanf("%d",&t);
    int arr[t];
    int l=0;
    while(t--)
    {
    char str[100];
    
    fflush(stdin);
    gets(str);
    
    int f[26]={0};
    int c=0;

    for(int i=0 ; i<strlen(str) ; i++)
    {
        int k= (int)str[i] -97 + 1;
        f[k-1]++;
    }

    for(int i=0 ; i<strlen(str) ; i++)
    {
        int k= (int)str[i] -97 + 1;
        if(f[k-1] != k)
        {
            c++;
            break;
        }
    }

    arr[l]=c;
    
    l++;
    
    }

    for (int i = 0; i < l; i++)
    {
        if(arr[i]==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    

    return 0;

}


