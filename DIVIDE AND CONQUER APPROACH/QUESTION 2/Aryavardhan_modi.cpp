/*
    Name : Aryavardhan Modi
    Time compilation : O(n)
    Better when we discuss the number of comparisions performed, we perform less comparisions in divide and conquer when compared to iterative
*/

#include<stdio.h>
#include<stdlib.h>

using namespace std;

int max, min; // globally varaibles  
int a[1000];

void max_min_dnc(int i, int j)
{
    int prev_max, prev_min, mid;

    if(i==j)
    {
        max = min = a[i]; // if a singleton array
    }
    else
    {
        if(i == j-1) // if only 2 elements present
        {
            if(a[i] <a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
    
        else
        {
            mid = (i+j)/2; //calculating pivot 
            max_min_dnc(i, mid); // finding max min for elements before pivot 
            prev_max = max; 
            prev_min = min;
            
            max_min_dnc(mid+1,j); // after pivot, recursively check for max min
            if(max <prev_max)
            max = prev_max;
            if(min > prev_min)
            min = prev_min;
        }
    }
}

int main ()
{
    int i, num;
    printf ("Enter the size =  \n");
    scanf ("%d",&num);
    printf ("Enter the numbers = \n");
    for (i=0;i<num;i++)
    scanf ("%d",&a[i]);
    max = a[0];
    min = a[0];
    max_min_dnc(0, num-1);
    printf("Minimum element in an array =  %d\n", min);
    printf("Maximum element in an array =  %d\n", max);
    return 0;
}