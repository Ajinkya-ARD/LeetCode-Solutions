# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:    
        l1 = ListNode(0)
        y = l1
        l2 = ListNode(0)
        z = l2
        head1 = head
        while head1:
            if head1.val < x:
                l1.next = ListNode(head1.val)
                l1 = l1.next
            else:
                l2.next = ListNode(head1.val)
                l2 = l2.next
            head1 = head1.next
        l1.next = z.next
        return y.next