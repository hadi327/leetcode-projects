class Solution:
    def pathSum(self, root, targetSum):
        result = []

        def dfs(node, target, path):
            if not node:
                return

            path.append(node.val)

            if not node.left and not node.right:
                if target == node.val:
                    result.append(path[:])
            else:
                dfs(node.left, target - node.val, path)
                dfs(node.right, target - node.val, path)

            path.pop()

        dfs(root, targetSum, [])

        return result