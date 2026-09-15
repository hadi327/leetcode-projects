class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        vector<pair<char, int>> chars(
            count.begin(),
            count.end()
        );

        sort(
            chars.begin(),
            chars.end(),
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            }
        );

        string result;

        for (auto& [c, freq] : chars) {
            result.append(freq, c);
        }

        return result;
    }
};