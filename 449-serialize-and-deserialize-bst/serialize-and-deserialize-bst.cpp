class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string result;

        function<void(TreeNode*)> dfs =
            [&](TreeNode* node) {
                if (node == nullptr) {
                    return;
                }

                result += to_string(node->val) + " ";

                dfs(node->left);
                dfs(node->right);
            };

        dfs(root);

        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        stringstream ss(data);
        vector<int> values;
        int value;

        while (ss >> value) {
            values.push_back(value);
        }

        int index = 0;

        function<TreeNode*(long long, long long)> build =
            [&](long long lower, long long upper) -> TreeNode* {
                if (index >= values.size()) {
                    return nullptr;
                }

                int value = values[index];

                if (value <= lower || value >= upper) {
                    return nullptr;
                }

                index++;

                TreeNode* node = new TreeNode(value);

                node->left = build(lower, value);
                node->right = build(value, upper);

                return node;
            };

        return build(LLONG_MIN, LLONG_MAX);
    }
};