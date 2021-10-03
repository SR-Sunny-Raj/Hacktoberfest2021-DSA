# include <iostream>
# include <string.h>
using namespace std;
int main()
{
    char str1[10];
    char str2[10];

    cout<<"Enter first string : ";
    cin>>str1;

    cout<<"Enter second string : ";
    cin>>str2;
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    bool found = 0;
    for(int i = 0; i < len1; i++)
    {
        found = 0;
        for(int j = 0; j < len2; j++)
        {
            if(str1[i] == str2[j])
            {
                found = 1;
                break;
            }
        }
    }
    if(found == 1)
    {
        cout<<"\n string is a anagram\n";
    }
    else
    {
        cout<<"\nString is not an anagram\n";
    }

return 0;
}
