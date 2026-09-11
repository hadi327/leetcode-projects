#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode** queue = malloc(10000 * sizeof(struct TreeNode*));

    // Maximum possible number of levels is 10000
    double* result = malloc(10000 * sizeof(double));

    int front = 0;
    int rear = 0;
    int levels = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        long long sum = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            sum += node->val;

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;
        }

        result[levels++] = (double)sum / levelSize;
    }

    free(queue);

    *returnSize = levels;
    return result;
}