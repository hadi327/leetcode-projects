class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        add(root, val, depth, 1);

        return root;
    }

private:
    void add(TreeNode* root, int val, int depth, int current) {
        if (root == nullptr)
            return;

        if (current == depth - 1) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            leftNode->left = root->left;
            rightNode->right = root->right;

            root->left = leftNode;
            root->right = rightNode;

            return;
        }

        add(root->left, val, depth, current + 1);
        add(root->right, val, depth, current + 1);
    }
};