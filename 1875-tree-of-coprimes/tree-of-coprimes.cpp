class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<pair<int, int>>> path;
    vector<int> ans;

    void dfs(int node, int parent, int depth, vector<int>& nums) {
        int value = nums[node];

        int bestNode = -1;
        int bestDepth = -1;

        // Find the deepest ancestor with gcd = 1
        for (int v = 1; v <= 50; v++) {
            if (!path[v].empty() && gcd(value, v) == 1) {
                auto [ancestor, ancestorDepth] = path[v].back();

                if (ancestorDepth > bestDepth) {
                    bestDepth = ancestorDepth;
                    bestNode = ancestor;
                }
            }
        }

        ans[node] = bestNode;

        // Add current node
        path[value].push_back({node, depth});

        for (int next : graph[node]) {
            if (next == parent)
                continue;

            dfs(next, node, depth + 1, nums);
        }

        // Remove current node when backtracking
        path[value].pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums,
                            vector<vector<int>>& edges) {
        int n = nums.size();

        graph.assign(n, {});
        ans.assign(n, -1);
        path.assign(51, {});

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, 0, nums);

        return ans;
    }
};