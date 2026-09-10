int ans = 0;

void dfs(struct TreeNode* root, int* sum, int* count) {
    if (root == NULL) {
        *sum = 0;
        *count = 0;
        return;
    }

    int leftSum, leftCount;
    int rightSum, rightCount;

    dfs(root->left, &leftSum, &leftCount);
    dfs(root->right, &rightSum, &rightCount);

    *sum = leftSum + rightSum + root->val;
    *count = leftCount + rightCount + 1;

    if (root->val == (*sum / *count)) {
        ans++;
    }
}

int averageOfSubtree(struct TreeNode* root) {
    ans = 0;

    int sum, count;
    dfs(root, &sum, &count);

    return ans;
}