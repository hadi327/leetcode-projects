class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size() / 3;
        int ans = 0;

        int i = piles.size() - 2;

        while (n--) {
            ans += piles[i];
            i -= 2;
        }

        return ans;
    }
};