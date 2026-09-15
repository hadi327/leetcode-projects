class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<int>& nums, int start, vector<int>& current) {
        if (current.size() >= 2)
            result.push_back(current);

        set<int> used;

        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;

            if (!current.empty() &&
                nums[i] < current.back())
                continue;

            used.insert(nums[i]);
            current.push_back(nums[i]);

            dfs(nums, i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();

        vector<int> current;
        dfs(nums, 0, current);

        return result;
    }
};