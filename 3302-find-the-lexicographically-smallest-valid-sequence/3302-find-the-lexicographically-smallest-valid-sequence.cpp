class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        // suf[i] = number of characters of word2
        // that can be matched using word1[i...n-1]
        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                --j;
            }
            suf[i] = m - 1 - j;
        }

        vector<int> ans;
        ans.reserve(m);

        int j2 = 0;
        bool changed = false;

        for (int i = 0; i < n && j2 < m; ++i) {

            // Exact match
            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                ++j2;
            }

            // Use our one allowed mismatch
            else if (!changed && suf[i + 1] >= m - j2 - 1) {
                ans.push_back(i);
                ++j2;
                changed = true;
            }
        }

        if (ans.size() == m)
            return ans;

        return {};
    }
};