# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # Initialize the output list to store the inorder traversal
        result = []
      
        # Continue traversing until there are no more nodes to process
        while root:
            # If there is no left child, add the current node's value to the result
            # and move to the right child
            if root.left is None:
                result.append(root.val)
                root = root.right
            else:
                # Find the rightmost node in the left subtree or the left child itself
                # if it does not have a right child. This node will be our "predecessor"
                predecessor = root.left
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
              
                # If the predecessor's right child is not set to the current node,
                # set it to the current node and move to the left child of the current node
                if predecessor.right is None:
                    predecessor.right = root
                    root = root.left
                else:
                    # If the predecessor's right child is set to the current node,
                    # it means we have processed the left subtree, so add the current
                    # node's value to the result and sever the temporary link to restore
                    # the tree structure. Then, move to the right child.
                    result.append(root.val)
                    predecessor.right = None
                    root = root.right
      
        # Return the result of the inorder traversal
        return result