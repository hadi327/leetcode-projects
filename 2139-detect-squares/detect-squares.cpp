
#include <bits/stdc++.h>
using namespace std;

class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> points;

public:
    DetectSquares() {}

    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        // Choose each stored point as the opposite corner
        for (auto &entry : points) {
            int x2 = entry.first;

            // Square must have non-zero width
            if (x2 == x) continue;

            for (auto &col : entry.second) {
                int y2 = col.first;

                // Square must have non-zero height and equal sides
                if (abs(y2 - y) != abs(x2 - x)) continue;

                int side = abs(x2 - x);

                // Other two corners
                int y3 = y;
                int y4 = y2;

                int count1 = points[x][y4];
                int count2 = points[x2][y3];

                ans += col.second * count1 * count2;
            }
        }

        return ans;
    }
};
