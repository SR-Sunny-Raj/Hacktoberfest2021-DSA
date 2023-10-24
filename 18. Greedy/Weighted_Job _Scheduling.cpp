/* Problem
 You are given N jobs where every job is represented as:
  1.Start Time
  2.Finish Time
  3.Profit Associated
  Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
  Input
  The first line of input contains one integer denoting N.
  Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
  
  Output
  Output one integer, the maximum profit that can be achieved.
  
  Constraints
  1 ≤ N ≤ 10^6
  1 ≤ ai, di, p ≤ 10^6
  
  Sample Input
  4
  3 10 20
  1 2 50
  6 19 100
  2 100 200
  
  Sample Output
  250
*/

//Solution Code

#include <iostream> 
#include <algorithm> 
using namespace std; 


struct Job 
{ 
	int start, finish, profit; 
}; 


bool jobComparataor(Job s1, Job s2) 
{ 
	return (s1.finish < s2.finish); 
} 


int latestNonConflict(Job arr[], int index) 
{ 
	int lo = 0, hi = index- 1; 


    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (arr[mid].finish <= arr[index].start) 
        { 
            if (arr[mid + 1].finish <= arr[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    }  
	return -1; 
} 





long long findMaxProfit(Job arr[], int n) 
{ 

	sort(arr, arr+n, jobComparataor); 

	long long *table = new long long[n]; 
    table[0] = arr[0].profit; 


    for (int i=1; i<n; i++) 
    { 

        long long inclProf = arr[i].profit; 
        int  l = latestNonConflict(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 


        table[i] = max(inclProf, table[i-1]); 
    } 


    long long result = table[n-1];
    return result;
} 


int main() 
{ 
    int n,i,start,finish,profit;
    cin>>n;
	Job arr[n];
    for(i=0;i<n;i++)
    {
        cin>>start>>finish>>profit;
        arr[i].start=start;
        arr[i].finish=finish;
        arr[i].profit=profit;
    }
    cout<<findMaxProfit(arr, n); 
	return 0; 
}
