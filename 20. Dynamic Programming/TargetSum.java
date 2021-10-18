public class TargetSum{
  
   public static void main(String args[]){
     int nums[]={1,3,5,2,6};
     int target=4;
     System.out.print(findTargetSumWays(nums,target));
   }
    public static int findTargetSumWays(int[] nums, int target) {
       HashMap<String,Integer> mp=new HashMap<>();
       return target(nums,target,0,mp);
        
    }
   static int target(int arr[],int sum,int ind,HashMap<String,Integer> mp){
        if(ind>=arr.length){
            if(sum==0) return 1;
            return 0;
        }
       String key=ind+":"+sum;
       if(mp.containsKey(key)){
           return mp.get(key);
       } 
       int left=target(arr,sum-arr[ind],ind+1,mp);
       int right=target(arr,sum+arr[ind],ind+1,mp);
       
          mp.put(key,left+right);
            return mp.get(key);
        
    }
  
}
