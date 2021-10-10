def twoSum(self, nums: List[int], target: int) -> List[int]:
  #  created a dictionary to store the occurrences of t         
  dic = {}
  n = len(nums)
  for i in range(n):
      # checking for the occurrence of the target number         
      if target - nums[i] in dic:
          return [ dic[ target - nums[i]],i ]
      dic[nums[i]] = i        
