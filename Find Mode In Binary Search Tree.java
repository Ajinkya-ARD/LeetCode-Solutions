/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int max = 0;
    int curr = Integer.MIN_VALUE;
    int count = 0;
    List<Integer> res = new LinkedList<>();
    public int[] findMode(TreeNode root) {
        countNode(root);

        int[] resArray = new int[res.size()];
        int index = 0;
        for (Integer ele:res) {
            resArray[index++] = ele;
        }
        return resArray;
    }
    private void countNode(TreeNode node) {
        if (node == null) {
            return;
        }
        countNode(node.left);
        if (node.val == curr) {
            count ++;

        }
        else {
            curr = node.val;
            count = 1;
        }
        if (count > max) {
            res.clear();
            max = count;
            res.add(node.val);
        }
        else if (count == max) {
            res.add(node.val);
        }
        countNode(node.right);
    }
}