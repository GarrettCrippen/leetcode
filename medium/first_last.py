class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        targets = []
        
        for i,val in enumerate(nums):
            if val == target:
                if len(targets)==2:
                    targets[1] = i
                else:
                    targets.append(i)
        

        if(len(nums)>=1 and len(targets) == 1):
            targets.append(targets[0])
            return targets
        
        elif(len(targets) == 2):
            return targets
        
        else:
            return [-1,-1]
