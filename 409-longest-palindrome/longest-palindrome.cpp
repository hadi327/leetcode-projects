class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        int result = 0;
        bool odd = false;

        for (auto& [ch, freq] : count) {
            result += (freq / 2) * 2;

            if (freq % 2 == 1) {
                odd = true;
            }
        }

        if (odd) {
            result++;
        }

        return result;
    }
};