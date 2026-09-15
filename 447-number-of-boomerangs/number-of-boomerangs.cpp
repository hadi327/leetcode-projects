class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;

        for (int i = 0; i < points.size(); i++) {
            unordered_map<long long, int> count;

            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;

                long long dx =
                    points[i][0] - points[j][0];

                long long dy =
                    points[i][1] - points[j][1];

                long long distance =
                    dx * dx + dy * dy;

                count[distance]++;
            }

            for (auto& [distance, frequency] : count) {
                result += frequency * (frequency - 1);
            }
        }

        return result;
    }
};