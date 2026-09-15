class Solution {
    vector<vector<int>> rects;
    vector<long long> prefix;
    long long total = 0;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;

        for (auto& r : rects) {
            long long points =
                1LL * (r[2] - r[0] + 1) *
                (r[3] - r[1] + 1);

            total += points;
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        long long randomPoint =
            rand() % total + 1;

        int index = lower_bound(prefix.begin(),
                                prefix.end(),
                                randomPoint) -
                    prefix.begin();

        auto& r = rects[index];

        int width = r[2] - r[0] + 1;

        long long previous =
            index == 0 ? 0 : prefix[index - 1];

        long long offset =
            randomPoint - previous - 1;

        int x = r[0] + offset % width;
        int y = r[1] + offset / width;

        return {x, y};
    }
};