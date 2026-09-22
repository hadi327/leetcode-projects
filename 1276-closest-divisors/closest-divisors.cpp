class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int bestDiff = INT_MAX;

        for (int x : {num + 1, num + 2}) {
            for (int i = sqrt(x); i >= 1; i--) {
                if (x % i == 0) {
                    int a = i;
                    int b = x / i;

                    if (b - a < bestDiff) {
                        bestDiff = b - a;
                        ans = {a, b};
                    }

                    break;
                }
            }
        }

        return ans;
    }
};