class Solution {
    public int subarrayGCD(int[] nums, int k) {
        int answer = 0;

        for (int i = 0; i < nums.length; i++) {
            int currentGcd = 0;

            for (int j = i; j < nums.length; j++) {
                currentGcd = gcd(currentGcd, nums[j]);

                if (currentGcd == k) {
                    answer++;
                }

                if (currentGcd < k) {
                    break;
                }
            }
        }

        return answer;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}