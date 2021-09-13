def findmin(heights: List[int]) -> list[int]:
    d=[]
    p=[]
    for i in range(len(heights)):
        d=[]
        for j in range(len(heights)):
            if j is i:
                d.append(heights[i])
            elif i<j:
                d.append(min(heights[j],d[j-1]))
            elif i>j:
                d.append(p[j][i])


        p.append(d)
    return p

class Solution:

    def largestRectangleArea(self, heights: List[int]) -> int:
        d=[]
        p=[]
        h=findmin(heights)
        for i in range(len(heights)):
            d=[]
            for j in range(len(heights)):
                
                if(not j and not i):
                    d.append(heights[i])
                elif(j and not i):
                    d.append(max(heights[j],h[i][j]*(abs(j-i)+1),d[j-1]))
                elif(not j and i):
                    d.append(max(heights[i],p[i-1][j]))
                elif(j and i):
                    d.append(max(heights[i],heights[j],p[i-1][j],h[i][j]*(abs(j-i)+1),d[j-1]))
            p.append(d)
        return p[len(heights)-1][len(heights)-1]
                
