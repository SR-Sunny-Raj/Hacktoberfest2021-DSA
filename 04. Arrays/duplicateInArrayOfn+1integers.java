//Find duplicate in an array of n+1 integers

import java.util.Arrays;

public class solution_3 {
    public static int findDuplicate(int[] nums) {

        Arrays.sort(nums,0,nums.length);
        int repeat=0;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                repeat=nums[i+1];
            }
            
        }
        return repeat;
    } 
       public static void main(String[] args){
        int[] nums = new int[]{9,4,1,5,3,4};
        findDuplicate(nums);
        System.out.println(findDuplicate(nums));
    }

}
