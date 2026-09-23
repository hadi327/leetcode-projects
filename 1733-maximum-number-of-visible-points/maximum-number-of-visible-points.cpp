class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle,
                      vector<int>& location) {

        const double PI = acos(-1.0);
        vector<double> angles;

        int same = 0;

        for (auto &p : points) {
            int dx = p[0] - location[0];
            int dy = p[1] - location[1];

            // Point is exactly at our location
            if (dx == 0 && dy == 0) {
                same++;
                continue;
            }

            double a = atan2(dy, dx) * 180.0 / PI;

            if (a < 0)
                a += 360.0;

            angles.push_back(a);
        }

        sort(angles.begin(), angles.end());

        int n = angles.size();

        // Duplicate angles to handle circular range
        vector<double> extended = angles;

        for (double a : angles)
            extended.push_back(a + 360.0);

        int ans = 0;
        int left = 0;

        for (int right = 0; right < extended.size(); right++) {

            while (extended[right] - extended[left] > angle + 1e-9)
                left++;

            ans = max(ans, right - left + 1);
        }

        return ans + same;
    }
};