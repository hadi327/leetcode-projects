class Solution {
public:
    int shoppingOffers(
        vector<int>& price,
        vector<vector<int>>& special,
        vector<int>& needs
    ) {
        map<vector<int>, int> memo;

        return dfs(price, special, needs, memo);
    }

private:
    int dfs(
        vector<int>& price,
        vector<vector<int>>& special,
        vector<int>& needs,
        map<vector<int>, int>& memo
    ) {
        if (memo.count(needs))
            return memo[needs];

        int result = 0;

        for (int i = 0; i < needs.size(); i++)
            result += needs[i] * price[i];

        for (auto& offer : special) {
            bool possible = true;

            for (int i = 0; i < needs.size(); i++) {
                if (offer[i] > needs[i]) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            for (int i = 0; i < needs.size(); i++)
                needs[i] -= offer[i];

            result = min(
                result,
                offer.back() +
                dfs(price, special, needs, memo)
            );

            for (int i = 0; i < needs.size(); i++)
                needs[i] += offer[i];
        }

        return memo[needs] = result;
    }
};