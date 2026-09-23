class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();

        vector<double> ans(n, -1.0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            double posI = cars[i][0];
            double speedI = cars[i][1];

            while (!st.empty()) {
                int j = st.top();

                double posJ = cars[j][0];
                double speedJ = cars[j][1];

                // i is not faster than j, so they never collide
                if (speedI <= speedJ) {
                    st.pop();
                    continue;
                }

                double time =
                    (posJ - posI) / (speedI - speedJ);

                // j never collides, or i reaches j before j collides
                if (ans[j] < 0 || time <= ans[j]) {
                    ans[i] = time;
                    break;
                }

                // j disappears into another car before i reaches it
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};