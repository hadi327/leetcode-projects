class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // i + 1 → each element can be used only once
            backtrack(candidates, target - candidates[i],
                      i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;
        backtrack(candidates, target, 0, current);

        return ans;
    }
};