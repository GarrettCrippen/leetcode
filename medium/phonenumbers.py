def e(digit:str):
    if(int(digit)==7):
        return chr(97+3*(int(digit)-2)),chr(98+3*(int(digit)-2)),chr(99+3*(int(digit)-2)),chr(100+3*(int(digit)-2))
    elif(int(digit)==8):
        return chr(97+3*(int(digit)-2)+1),chr(98+3*(int(digit)-2)+1),chr(99+3*(int(digit)-2)+1)
    elif int(digit)==9:
        return chr(97+3*(int(digit)-2)+1),chr(98+3*(int(digit)-2)+1),chr(99+3*(int(digit)-2)+1),chr(100+3*(int(digit)-2)+1)
    return chr(97+3*(int(digit)-2)),chr(98+3*(int(digit)-2)),chr(99+3*(int(digit)-2))
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        sz=len(digits)
        if sz==0:
            return []
        valid=[]
        a,b,c,d=[],[],[],[]
        if sz >=1:            
            a=e(digits[0])
        if sz >=2:  
            b=e(digits[1])
        if sz >=3:  
            c=e(digits[2])
        if sz >=4:  
            d=e(digits[3])
        for val in a:
            if sz==1:
                valid.append(val)
            for val1 in b:
                if sz==2:
                    print(val,val1)
                    valid.append(val+val1)
                for val2 in c:
                    if sz==3:
                        valid.append(val+val1+val2)
                    for val3 in d:
                        if sz==4:
                            valid.append(val+val1+val2+val3)
        return valid
                     

