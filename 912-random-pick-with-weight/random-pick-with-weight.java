class Solution {
    int[] prefix;
    int total;
    Random random = new Random();

    public Solution(int[] w) {
        prefix = new int[w.length];

        int sum = 0;

        for (int i = 0; i < w.length; i++) {
            sum += w[i];
            prefix[i] = sum;
        }

        total = sum;
    }

    public int pickIndex() {
        int target = random.nextInt(total) + 1;

        int left = 0;
        int right = prefix.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (prefix[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
}