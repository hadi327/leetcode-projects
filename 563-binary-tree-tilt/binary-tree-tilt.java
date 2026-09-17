class Solution {
    int result = 0;

    public int findTilt(TreeNode root) {
        sum(root);
        return result;
    }

    private int sum(TreeNode root) {
        if (root == null)
            return 0;

        int left = sum(root.left);
        int right = sum(root.right);

        result += Math.abs(left - right);

        return left + right + root.val;
    }
}