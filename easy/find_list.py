class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        k = i+1

        while k < len(nums):
            if nums[i] == nums[k]:
                nums[k] = 999
                temp = nums[k]
                k+=1
            else:
                i+=1
                k=i+1

                
        nums.sort()
        try:
            return len(nums[:nums.index(999)])
        except:
            return len(nums)
