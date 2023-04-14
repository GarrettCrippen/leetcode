class Solution:
    #let's create a dictionary {int:freq}, sort by the freq and return the first k
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        myDict ={}
        for num in nums:
            myDict[num] = myDict.get(num,1)+1

        myTuple = sorted(myDict.items(),key=lambda freq: freq[1],reverse=True)
        res = [x[0] for x in myTuple[:k]]
        return res