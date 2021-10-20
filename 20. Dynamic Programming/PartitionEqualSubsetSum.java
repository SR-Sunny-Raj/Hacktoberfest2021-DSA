public class PartitionEqualSubsetSum{

   public static void main(String args[]){
     int nums[]={1,3,5,2,6,3};
     System.out.print(canPartition(nums));
   }
    public static boolean canPartition(int[] nums) {
        int n=nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        
        int dp[][]=new int[nums.length+1][(sum/2)+1];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                dp[i][j]=-1;
            }
        }

        return subset(nums,sum/2,0,dp)==1;
    } 
    static int subset(int arr[],int val,int ind,int dp[][]){
        if(ind>=arr.length){
            if(val==0) return 1 ;
            return 0;
        }
        if(dp[ind][val]!=-1){
           return dp[ind][val];
        }
        int taken=0;
        if(arr[ind]<=val){
        taken=subset(arr,val-arr[ind],ind+1,dp);
        }
        int nottaken=subset(arr,val,ind+1,dp);
       return dp[ind][val]=(taken | nottaken);
       
        }
        
}
