/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int PathSum(TreeNode root, int targetSum) {
        Dictionary<long, int> prefix = new Dictionary<long, int>();
        prefix[0] = 1;

        return DFS(root, 0, targetSum, prefix);
    }

    private int DFS(TreeNode node, long currentSum, int targetSum, Dictionary<long, int> prefix) {
        if (node == null) {
            return 0;
        }

        currentSum += node.val;

        int count = 0;

        if (prefix.ContainsKey(currentSum - targetSum)) {
            count += prefix[currentSum - targetSum];
        }

        if (!prefix.ContainsKey(currentSum)) {
            prefix[currentSum] = 0;
        }
        prefix[currentSum]++;

        count += DFS(node.left, currentSum, targetSum, prefix);
        count += DFS(node.right, currentSum, targetSum, prefix);

        prefix[currentSum]--;

        return count;
    }
}