/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] res = new ListNode[k];

        if (root == null) {
            return res;
        }

        ListNode curNode = root;
        int count = 0;

        while (curNode != null) {
            curNode = curNode.next;
            ++count;
        }

        int size = count / k, rem = count % k;

        curNode = root;
        for (int i = 0; i < k; i++) {
            ListNode dummy = new ListNode(0);
            ListNode temp = dummy;

            for (int j = 0; j < size + (i < rem ? 1 : 0); j++) {
                temp.next = new ListNode(curNode.val);
                temp = temp.next;
                curNode = curNode.next;
            }
            res[i] = dummy.next;
        }
        return res;
    }
}