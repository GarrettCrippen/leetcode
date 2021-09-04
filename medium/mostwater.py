# Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
import numpy as np
class Solution(object):
    def maxArea(self, height):
        new=[]
        twod_list=[]
        
        #i rows x j columns
        if len(height) <4500:
            for i in range(len(height)):
                new=[]
                for j in range(len(height)):
                    if i==0 and j==0:
                        new.append(0)
                    else:
                        current = (abs(j-i))*min(height[i],height[j])
                        if not len(twod_list) and len(new):
                             new.append(max(new[j-1],current))
                        elif len(twod_list) and len(new):
                                new.append(max(new[j-1],current,twod_list[i-1][j]))
                        elif len(twod_list) and not len(new):
                                new.append(max(current,twod_list[i-1][j]))  
                twod_list.append(new)
            #print (np.shape(twod_list))     
            #print (twod_list)
            return twod_list[len(height)-1][len(height)-1]
        
        l=0
        r=len(height)-1
        largest=0
        while(l<r):
            largest=max(abs(l-r)*min(height[l],height[r]),largest)
            if(height[l]<height[r]):
                l+=1
            else:
                r-=1
            largest=max(abs(l-r)*min(height[l],height[r]),largest)
        return largest
        """
        :type height: List[int]
        :rtype: int
        """
        
