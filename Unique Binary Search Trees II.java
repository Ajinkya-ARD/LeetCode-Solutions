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
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode>[][] dp = new List[n][n];
        int[] nums = new int[n];
        for(int i = 0; i < n; i++){
            nums[i] = i+1;
        }
        if(n == 0){
            return new ArrayList<>();
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                dp[i][j] = new ArrayList<>();
                List<TreeNode> one = new ArrayList<>();
                one.add(null);
                if(j == i){
                    TreeNode root = new TreeNode(nums[i]);
                    dp[i][j].add(root);
                    continue;
                }
                for(int k = i; k <= j; k++){
                    List<TreeNode> left = k==i ? one : dp[i][k-1];
                    List<TreeNode> right = k==j ? one : dp[k+1][j];
                    for(TreeNode l : left){
                        for(TreeNode r : right){
                            TreeNode root = new TreeNode(nums[k]);
                            root.left = l;
                            root.right = r;
                            dp[i][j].add(root);
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
}