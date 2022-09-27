# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = []
        
        temp = root
        
        while(True):
            
            #keep going down to left most child
            if temp != None:
                stack.append(temp)
                temp = temp.left
            
            #append last node and then go down right side of next node in stack
            elif(stack):
                temp = stack.pop()
                res.append(temp.val)
                temp = temp.right
            else:
                break

                    
        return res
