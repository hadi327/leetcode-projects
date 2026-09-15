class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string cleaned;

        for (char c : s) {
            if (c != '-')
                cleaned += toupper(c);
        }

        int first = cleaned.size() % k;
        string result;

        if (first > 0) {
            result += cleaned.substr(0, first);
        }

        for (int i = first; i < cleaned.size(); i += k) {
            if (!result.empty())
                result += '-';

            result += cleaned.substr(i, k);
        }

        return result;
    }
};