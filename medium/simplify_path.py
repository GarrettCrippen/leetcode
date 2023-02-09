import re

class Solution(object):
    def simplifyPath(self, path):
        #strip starting /
        
        #remove duplicates
        mypath=re.sub(r'/+',r'/',path)
    
        mypaths = mypath.split('/')

        res = []

        for path in mypaths:
            if path:
                if(path == '..'):
                    res.pop()
                elif(path == '.'):
                    continue
                else(res.append(path))

        return '/'+'/'.join(res)


def main():
    S = Solution()
    S.simplifyPath('/home///..///foo/')

main()