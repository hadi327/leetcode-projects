class Solution {
    public int subarrayLCM(int[] nums, int k) {
        int answer = 0;

        for (int i = 0; i < nums.length; i++) {
            long lcm = 1;

            for (int j = i; j < nums.length; j++) {
                lcm = lcm(lcm, nums[j]);

                if (lcm == k) {
                    answer++;
                }

                if (lcm > k || k % lcm != 0) {
                    break;
                }
            }
        }

        return answer;
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}