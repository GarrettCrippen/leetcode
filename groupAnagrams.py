class Solution:

    #Only check strings of the same len
    
    def Anagram(self, s: str) -> frozenset:
        myDict = {}
        #add to set
        for c in s:
            myDict[c] = myDict.get(c,0) +1  
        
        sorted_tuples = sorted(myDict.items())
        frozen_set = frozenset(sorted_tuples)

        return frozen_set

    #hash anagrams to a dictionary, store value as a list
    #at the end iterate through the dictionary and append the lists to a list
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        myDict = {}
        #iterate in selection sort type of way
        for i in range(len(strs)):
            temp = self.Anagram(strs[i])
            if temp in myDict:
                myDict[temp].append(strs[i])
            else:
                myDict[temp] = [strs[i]]


        myList = []
        for key, value in myDict.items():
            myList.append(value)

        return myList