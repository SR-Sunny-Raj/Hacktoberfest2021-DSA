#Input: nums = [1,2,3]
#Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
  
  def subsets(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.helper(nums, 0, [])
        return self.result
    
    def helper(self, nums, start, subset):
        self.result.append(subset[::])
        
        for i in range(start, len(nums)):
            subset.append(nums[i])
            self.helper(nums, i + 1, subset)
            subset.pop()
