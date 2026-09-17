class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> result = new ArrayList<>();

        dfs(root, result);

        return result;
    }

    private void dfs(Node root, List<Integer> result) {
        if (root == null)
            return;

        result.add(root.val);

        for (Node child : root.children)
            dfs(child, result);
    }
}