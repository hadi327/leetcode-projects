class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int currentMax = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int bestLeft = pq.top()[0];
        int bestRight = currentMax;

        while (true) {
            auto current = pq.top();
            pq.pop();

            int value = current[0];
            int list = current[1];
            int index = current[2];

            if (currentMax - value <
                    bestRight - bestLeft) {
                bestLeft = value;
                bestRight = currentMax;
            }

            if (index + 1 == nums[list].size())
                break;

            int next = nums[list][index + 1];

            pq.push({next, list, index + 1});
            currentMax = max(currentMax, next);
        }

        return {bestLeft, bestRight};
    }
};