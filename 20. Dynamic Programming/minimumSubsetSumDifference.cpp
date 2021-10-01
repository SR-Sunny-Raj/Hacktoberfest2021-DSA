/***********************Hacktober Fest 2021******************/

/*****
	Solution by :- manishmotwani2002(Github Username)
	Question:- Minimum Subset Sum Difference
	Explaination:- Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
	
	Input:- 
	4
	1 6 11 5
	
	Output:- 
	1
	
	Justification:- 
	
	Subset1 = {1, 5, 6}, sum of Subset1 = 12 
	Subset2 = {11}, sum of Subset2 = 11    
	
***********/



#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int nums[],int sum,int n) {		//function for calculating subset sum
	
	vector<int> vtt;
    int i,j;
    bool arr[n+1][sum+1];
        
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                arr[i][j]=false;
            }
            if(j==0)
            {
                arr[i][j]=true;
            }
                
        }
    }
    for(i=1;i<n+1;i++)
    	{
        for(j=0;j<sum+1;j++)
        {
            if(nums[i-1]<=j)
            {
                arr[i][j]=(arr[i-1][j-nums[i-1]]) || (arr[i-1][j]);
            }
            else
            {
                arr[i][j]=arr[i-1][j];
            }
        }
    }
    for(j=0;j<sum+1;j++)
    {
        if(arr[n][j]==true)
        vtt.push_back(j);
    }
    return vtt;
}

int minDiffernce(int arr[], int n) 		//evaluating min difference on the basis of subset sum array
{ 
	int sum=0,i,j,ans=INT_MAX;
	for(i=0;i<n;i++)
	sum+=arr[i];
	    
	vector<int> temp=subsetSum(arr,sum,n);
	for(i=0;i<temp.size();i++)
	{
		int diff=abs(sum-2*temp[i]);
		  ans=min(ans,diff);
	}
	return ans;
} 


int main()
{
	int n,i;
	cin>>n;			//total number of elements in array
	
	int arr[n];		
	
	for(i=0;i<n;i++)
	cin>>arr[i];	//taking input of array elements
	
	cout<<minDiffernce(arr,n);
}



