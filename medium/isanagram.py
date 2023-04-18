class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        myDict = {}

        #saves us time
        if len(s) != len(t):
            return False

        #add to set
        for c in s:
            if c in myDict:
                myDict[c]+=1
            else:
                myDict[c]=1
        
        for c in t:
            if c not in myDict:
                return False
            else:
                myDict[c]-=1
                if myDict[c] < 0:
                    return False
        
        return True
    
        # def isAnagram(self, s: str, t: str) -> bool:
        # myDict1, myDict2 = {}, {}

        # #saves us time
        # if len(s) != len(t):
        #     return False

        # for c in s:
        #     myDict1[c] = myDict1.get(c,0)+1
        
        # for c in t:
        #     myDict2[c] = myDict2.get(c,0)+1
        
        # return myDict1 == myDict2   