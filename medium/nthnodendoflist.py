# Given the head of a linked list, remove the nth node from the end of the list and return its head.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def findTail(head):
    size=0
    while(head):
        head=head.next
        size+=1
    return size
    
class Solution(object):

    
    def removeNthFromEnd(self, head, n):
        size=findTail(head)
        temp=head
        prev=head
        remove=0
        while(temp and remove!=size-n):
            prev=temp
            temp=temp.next
            remove+=1
        
        if size-n==0:
            temp=head.next
            del head
            head=temp
        else:
            print(prev.val,temp.val)
            prev.next=temp.next
            del temp   
            
        return head
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
