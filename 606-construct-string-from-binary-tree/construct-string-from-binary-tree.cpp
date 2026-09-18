class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr)
            return "";

        string result = to_string(root->val);

        if (root->left != nullptr) {
            result += "(";
            result += tree2str(root->left);
            result += ")";
        }

        if (root->right != nullptr) {
            if (root->left == nullptr)
                result += "()";

            result += "(";
            result += tree2str(root->right);
            result += ")";
        }

        return result;
    }
};