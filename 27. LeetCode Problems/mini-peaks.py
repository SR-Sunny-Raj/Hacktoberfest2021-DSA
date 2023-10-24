def miniPeaks(nums):
    result = []
    left = 0
    right = 0
    
    for i in range(1, len(nums) - 1):
        left = nums[i - 1]
        right = nums[i + 1]
        
        if nums[i] > left and nums[i] > right:
            result.append(nums[i])
            
    return result

# Time Complexity : O(n)
# Space Complexity : O(m),
# n = nos of elements
# m = nos of peak elements

