class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long answer = 0;
        long zeros = 0;

        for (int num : nums) {
            if (num == 0) {
                zeros++;
                answer += zeros;
            } else {
                zeros = 0;
            }
        }

        return answer;
    }
}