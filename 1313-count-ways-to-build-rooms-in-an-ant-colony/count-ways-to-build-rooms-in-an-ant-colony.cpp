class Solution {
public:
    static const long long MOD = 1000000007;

    vector<vector<int>> tree;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    long long C(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD
             * invFact[n - r] % MOD;
    }

    pair<int, long long> dfs(int node) {
        int size = 1;
        long long ways = 1;

        // Number of nodes already arranged
        int processed = 0;

        for (int child : tree[node]) {
            auto [childSize, childWays] = dfs(child);

            // Interleave this child's subtree
            // with all previously processed subtrees.
            ways = ways * childWays % MOD;
            ways = ways * C(processed + childSize, childSize) % MOD;

            processed += childSize;
            size += childSize;
        }

        return {size, ways};
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();

        tree.resize(n);

        for (int i = 1; i < n; i++) {
            tree[prevRoom[i]].push_back(i);
        }

        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return dfs(0).second;
    }
};