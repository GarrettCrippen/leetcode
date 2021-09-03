# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

# Notice that the solution set must not contain duplicate triplets.
class Solution(object):
    def threeSum(self, nums):
        d = {}
        l=[]
        nums.sort()
        i = 0
        j=i+1
        k=len(nums)-1
        for i in range(len(nums)-2):
            j=i+1
            k=len(nums)-1
            while j<k:
                sum =nums[i]+nums[j]+nums[k]
                #print(nums[i],nums[j],nums[k])
                
                if i!=j and i!=k and j!=k and \
                sum==0:
                    if not d.has_key(frozenset([nums[i],nums[j],nums[k]])):
                        l.append([nums[i],nums[j],nums[k]])

                    d[frozenset([nums[i],nums[j],nums[k]])]=1

                if sum<0:
                    j+=1
                else:
                    k-=1

            
        return l
        """ 
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
