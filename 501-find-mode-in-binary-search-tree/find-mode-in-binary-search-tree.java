class Solution {
    List<Integer> result = new ArrayList<>();
    Integer prev = null;
    int count = 0;
    int maxCount = 0;

    public int[] findMode(TreeNode root) {
        inorder(root);

        int[] ans = new int[result.size()];
        for (int i = 0; i < result.size(); i++)
            ans[i] = result.get(i);

        return ans;
    }

    private void inorder(TreeNode root) {
        if (root == null) return;

        inorder(root.left);

        if (prev != null && prev == root.val)
            count++;
        else
            count = 1;

        if (count > maxCount) {
            result.clear();
            maxCount = count;
            result.add(root.val);
        } else if (count == maxCount) {
            result.add(root.val);
        }

        prev = root.val;

        inorder(root.right);
    }
}