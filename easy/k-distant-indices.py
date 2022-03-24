class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        output=set()
        for index in range(len(nums)):
            for index2 in range(len(nums)):
                if abs(index-index2) <= k and nums[index2]==key:
                    output.add(index)
        output=list(output)
        output.sort()
        return output
