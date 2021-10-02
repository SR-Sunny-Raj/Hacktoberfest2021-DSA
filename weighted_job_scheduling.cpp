//Problem Link : https://www.geeksforgeeks.org/weighted-job-scheduling/

//Solution :

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int start, finish, profit; 
}; 
  

bool myfunction(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 

int binarySearch(Job jobs[], int index) 
{ 
    
    int lo = 0, hi = index - 1; 
  
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (jobs[mid].finish <= jobs[index].start) 
        { 
            if (jobs[mid + 1].finish <= jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 
 
int findMaxProfit(Job arr[], int n) 
{ 
    sort(arr, arr+n, myfunction); 
  
    
    int *table = new int[n]; 
    table[0] = arr[0].profit; 
  
    
    for (int i=1; i<n; i++) 
    { 
        
        int inclProf = arr[i].profit; 
        int l = binarySearch(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 
  
        
        table[i] = max(inclProf, table[i-1]); 
    } 
  
    
    int result = table[n-1]; 
    delete[] table; 
  
    return result; 
} 
int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for(int i= 0; i < n; i++){
        int ai,di,p;
        cin>>ai>>di>>p;
        arr[i].start = ai;
        arr[i].finish = di;
        arr[i].profit = p;
        
    }
    cout<<findMaxProfit(arr,n);
   
    return 0;
}