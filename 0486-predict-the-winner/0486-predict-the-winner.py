class Solution(object):
    def predictTheWinner(self, nums):
      # Shortcut: Player 1 always wins if the array length is even!
        if len(nums) % 2 == 0:
            return True
        
        # Fallback to memoized DFS for odd lengths
        memo = {}
        def solve(i, j):
            if i == j:
                return nums[i]
            if (i, j) in memo:
                return memo[(i, j)]
            
            res = max(nums[i] - solve(i + 1, j), nums[j] - solve(i, j - 1))
            memo[(i, j)] = res
            return res
            
        return solve(0, len(nums) - 1) >= 0