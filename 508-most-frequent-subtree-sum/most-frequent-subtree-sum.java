class Solution {
    Map<Integer, Integer> frequency = new HashMap<>();
    int maxFrequency = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        calculateSum(root);

        List<Integer> result = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : frequency.entrySet()) {
            if (entry.getValue() == maxFrequency)
                result.add(entry.getKey());
        }

        int[] ans = new int[result.size()];

        for (int i = 0; i < result.size(); i++)
            ans[i] = result.get(i);

        return ans;
    }

    private int calculateSum(TreeNode root) {
        if (root == null)
            return 0;

        int sum = root.val +
                  calculateSum(root.left) +
                  calculateSum(root.right);

        int count = frequency.getOrDefault(sum, 0) + 1;
        frequency.put(sum, count);

        maxFrequency = Math.max(maxFrequency, count);

        return sum;
    }
}