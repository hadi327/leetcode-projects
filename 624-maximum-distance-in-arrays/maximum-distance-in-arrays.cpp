class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minValue = arrays[0].front();
        int maxValue = arrays[0].back();

        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            result = max(result,
                         arrays[i].back() - minValue);

            result = max(result,
                         maxValue - arrays[i].front());

            minValue = min(minValue, arrays[i].front());
            maxValue = max(maxValue, arrays[i].back());
        }

        return result;
    }
};