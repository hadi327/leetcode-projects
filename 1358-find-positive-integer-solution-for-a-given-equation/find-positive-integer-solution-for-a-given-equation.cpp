class Solution {
public:
    vector<vector<int>> findSolution(
        CustomFunction& customfunction,
        int z
    ) {
        vector<vector<int>> ans;

        int x = 1;
        int y = 1000;

        while (x <= 1000 && y >= 1) {
            int value = customfunction.f(x, y);

            if (value == z) {
                ans.push_back({x, y});
                x++;
                y--;
            }
            else if (value < z) {
                x++;
            }
            else {
                y--;
            }
        }

        return ans;
    }
};