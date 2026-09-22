class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Prefix sum 0 has appeared once
        freq[0] = 1;

        int sum = 0;
        int answer = 0;

        for (int num : nums) {
            // Convert odd/even into 1/0
            sum += num % 2;

            // Need an earlier prefix sum of sum - k
            if (freq.count(sum - k)) {
                answer += freq[sum - k];
            }

            freq[sum]++;
        }

        return answer;
    }
};