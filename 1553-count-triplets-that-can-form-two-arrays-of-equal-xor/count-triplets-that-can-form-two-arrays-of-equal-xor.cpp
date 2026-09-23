class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int xr = 0;

            for (int j = i; j < n; j++) {
                xr ^= arr[j];

                if (xr == 0) {
                    ans += j - i;
                }
            }
        }

        return ans;
    }
};