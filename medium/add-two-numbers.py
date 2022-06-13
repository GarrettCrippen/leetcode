# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        total1 = 0
        place1 = 0
        
        while(l1):
            total1 += l1.val*(10**place1)
            place1+=1
            l1 = l1.next
         
        
        total2 = 0
        place2 = 0
        
        while(l2):
            total2 += l2.val*(10**place2)
            place2+=1
            l2 = l2.next
            
        total3 = total1+total2
        
        #first value of total
        root = ListNode(total3%10)
        total3 = total3//10
        
        temp = root
        while(total3 > 0):
            temp.next = ListNode(total3%10)
            temp = temp.next
            total3 = total3//10
            
            
        return root
        

