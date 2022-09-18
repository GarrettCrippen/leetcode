
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        def enumerateP(self, st, concat,l_n,r_n):
            if st == 'l':
                concat +='('
            elif st == 'r':
                concat +=')'
            if l_n >= r_n and l_n < n:
                enumerateP(self, 'l',concat,l_n+1,r_n)
            if l_n > r_n:
                enumerateP(self, 'r',concat,l_n,r_n+1)
                
            if(l_n == n and r_n == n):
                result.append(concat)
                #print(concat)
                return
        enumerateP(self,'l','',1,0)
        return result




    
            
