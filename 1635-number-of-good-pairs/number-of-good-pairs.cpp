class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int x : nums) {
            ans += freq[x];
            freq[x]++;
        }

        return ans;
    }
};