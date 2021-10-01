//the problem statement is https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/*Traverse the given array and follow the below steps :

Initialize two variable leftOnes ans rightOnes which counts 1's left side to 0 and other will count 1's right to 0 respectively.
If you get 1 while traversing increment rightOnes.
Else add two variables and compare it to the maxOnes variable which stores maximum consecutive 1's and change leftOnes to rightOnes and rightOnes to zero.
If by chance rightOnes==nums.length return rightOnes-1 as we have to delete one integer, otherwise return maxOnes. */

//Implementation of above approach :

int longestSubarray(int[] nums) {
        int leftOnes = 0; //count left side no of 1s to encountered 0
        int rightOnes = 0; //count right side no. of 1s to encountered 0
        int maxOnes = 0; //to store ans
        for(int i=0 ; i<nums.length ; i++){
            if(nums[i] == 0){
                int consOnes = leftOnes + rightOnes; //can be merged the left 1s and right 1s half
                maxOnes = Math.max(maxOnes, consOnes);
                leftOnes = rightOnes; //as now our next consecutive block that can be merged will begin from right end of encountred zero
                rightOnes = 0;
            }
            else{
                rightOnes++;
            }
        }
        if(rightOnes == nums.length) return rightOnes-1;
        int consOnes = leftOnes + rightOnes;
        return Math.max(consOnes, maxOnes);
    }
}

int main(){
    int n;
    cin>>n;
    int nums[n];

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans=longestSubarray(nums);
    cout<<ans<<endl;

    return 0;
}

//Time Complexity : O(n)
//Auixilary Space : O(1)