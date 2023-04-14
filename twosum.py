class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myDict = {}
        for i, value in enumerate(nums):
            if target-value in myDict:
                return [myDict[target-value],i]
            else:
                myDict[value]=i