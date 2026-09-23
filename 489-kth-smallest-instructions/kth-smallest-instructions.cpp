class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];

        string ans;

        while (h > 0 || v > 0) {
            // Number of paths if we choose H now
            long long waysH = 0;

            if (h > 0) {
                waysH = 1;

                // C(h + v - 1, v)
                int total = h + v - 1;
                int choose = min(v, total - v);

                for (int i = 1; i <= choose; i++) {
                    waysH = waysH * (total - choose + i) / i;
                }
            }

            if (h > 0 && k <= waysH) {
                // kth path is inside the H group
                ans += 'H';
                h--;
            } else {
                // Skip all H-starting paths
                if (h > 0)
                    k -= waysH;

                ans += 'V';
                v--;
            }
        }

        return ans;
    }
};