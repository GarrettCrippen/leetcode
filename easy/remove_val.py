class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        to_pop =[]
        try:
            while(True):
                nums.remove(val)
        except:
            return
