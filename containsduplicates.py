
#use hash-set or set datastructure instead to just store key values.
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        my_dict = {}
        for num in nums:
            if(my_dict.get(num)):
                return True
            else:
                my_dict.update({num:1})
        return False