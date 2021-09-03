#atoi
import sys
class Solution(object):
    def myAtoi(self, s):
        s=s.strip()
        total = 0
        Neg =False
        
        if len(s) and s[0]=='-':
            Neg=True
            s=s[1:]     
        elif len(s) and s[0]=='+':
            Neg=False
            s=s[1:]
        max=2**31-1
        min=-2**31
        for i in range(len(s)):         
            if s[i].isdigit():
                total*=10
                total+=int(s[i])
            else:
                break;

        if Neg and total*-1<=min:
                return min
        elif not Neg and total>=max:
                return max        
                
        if Neg: 
            return total*-1 
        else: 
            return total
        """
        :type s: str
        :rtype: int
        """
        
