class Solution
{
    public static int removeDuplicates(int[] nums)
    {
        //check if the array has more than one element or not
        if (nums.length < 2)
        {
            return nums.length;
        }
        int a = 0;
        int b = 1;

        //while loop to check for duplicates
        while (b < nums.length)
        {
            //if loop to check if two elements are same or not
            if (nums[b] != nums[a])
            {
                a++;
                nums[a] = nums[b];
            }

            b++;
        }

        return a + 1;
    }
}