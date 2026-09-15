class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);

        int current = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 &&
                (s[i] - s[i - 1] == 1 ||
                 s[i - 1] == 'z' && s[i] == 'a')) {
                current++;
            } else {
                current = 1;
            }

            int index = s[i] - 'a';
            dp[index] = max(dp[index], current);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};