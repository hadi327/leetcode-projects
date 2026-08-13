class Solution {
public:

    struct Node {
        int l, r;
        int lmx, rmx, mx;
    };

    vector<Node> tree;
    string s;

    void merge(int node) {

        Node &cur = tree[node];
        Node &L = tree[node * 2];
        Node &R = tree[node * 2 + 1];

        cur.l = L.l;
        cur.r = R.r;

        cur.lmx = L.lmx;
        cur.rmx = R.rmx;

        cur.mx = max(L.mx, R.mx);

        // Can the suffix of left connect
        // with the prefix of right?
        if (s[L.r] == s[R.l]) {

            if (L.lmx == L.r - L.l + 1)
                cur.lmx += R.lmx;

            if (R.rmx == R.r - R.l + 1)
                cur.rmx += L.rmx;

            cur.mx = max(cur.mx, L.rmx + R.lmx);
        }
    }

    void build(int node, int l, int r) {

        tree[node].l = l;
        tree[node].r = r;

        if (l == r) {
            tree[node].lmx = 1;
            tree[node].rmx = 1;
            tree[node].mx = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        merge(node);
    }

    void update(int node, int pos, char c) {

        if (tree[node].l == tree[node].r) {
            return;
        }

        int mid = (tree[node].l + tree[node].r) / 2;

        if (pos <= mid)
            update(node * 2, pos, c);
        else
            update(node * 2 + 1, pos, c);

        merge(node);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;
            this->s[pos] = c;

            update(1, pos, c);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};