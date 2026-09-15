class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> row;

        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        for (char c : r1)
            row[c] = 1;

        for (char c : r2)
            row[c] = 2;

        for (char c : r3)
            row[c] = 3;

        vector<string> result;

        for (string word : words) {
            int currentRow =
                row[tolower(word[0])];

            bool valid = true;

            for (char c : word) {
                if (row[tolower(c)] != currentRow) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                result.push_back(word);
        }

        return result;
    }
};