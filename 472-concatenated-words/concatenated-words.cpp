class Solution {
public:
    unordered_set<string> words;
    unordered_map<string, bool> memo;

    bool canForm(string word) {
        if (memo.count(word))
            return memo[word];

        int n = word.size();

        for (int i = 1; i < n; i++) {
            string left = word.substr(0, i);
            string right = word.substr(i);

            if (words.count(left) &&
                (words.count(right) || canForm(right))) {
                return memo[word] = true;
            }
        }

        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(
        vector<string>& wordsList) {

        for (string& word : wordsList)
            words.insert(word);

        vector<string> result;

        for (string& word : wordsList) {
            words.erase(word);

            memo.clear();

            if (canForm(word))
                result.push_back(word);

            words.insert(word);
        }

        return result;
    }
};