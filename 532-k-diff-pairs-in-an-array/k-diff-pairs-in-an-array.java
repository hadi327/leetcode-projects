class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0)
            return 0;

        Map<Integer, Integer> map = new HashMap<>();

        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);

        int result = 0;

        for (int num : map.keySet()) {
            if (k == 0) {
                if (map.get(num) > 1)
                    result++;
            } else {
                if (map.containsKey(num + k))
                    result++;
            }
        }

        return result;
    }
}