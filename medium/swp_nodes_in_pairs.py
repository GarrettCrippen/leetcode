# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        #special cases
        if(head == None or head.next == None):
            return head
        
        temp = head
        head = temp.next 
        last_swp = None
        
        while(temp != None):      
            
            #2nd node
            temp_next = temp.next

            #save next of (2nd node)
            if(temp_next != None):
                temp_next_next = temp_next.next
            else:
                temp_next_next = None
            
            #assign 2nd node to point to first node
            if(temp_next != None):
                temp_next.next = temp
                #print(f'{temp_next.val}->{temp.val}')
                    
            #assign last node in last adjacent pair's next to 2nd node
            if(last_swp != None):
                #odd case
                if(temp_next == None):
                    last_swp.next = temp
                #even case
                else:
                    last_swp.next = temp.next
            
            #start at 2nd adjacent pair
            last_swp = temp
            temp = temp_next_next
            
        last_swp.next = None    
        return head
