class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;

        int total = 1 << n;

        for (int i = 0; i < total; i++) {
            int gray = i ^ (i >> 1);
            ans.push_back(gray);
        }

        // Find where start occurs
        int pos = 0;

        for (int i = 0; i < total; i++) {
            if (ans[i] == start) {
                pos = i;
                break;
            }
        }

        // Rotate sequence
        rotate(ans.begin(), ans.begin() + pos, ans.end());

        return ans;
    }
};