import java.util.*;

class Solution {
    // ==================== APPROACH 1: Recursion with Memoization ====================
    public boolean isMatchRecursive(String s, String p) {
        Boolean[][] memo = new Boolean[s.length() + 1][p.length() + 1];
        return dp(0, 0, s, p, memo);
    }
    
    private boolean dp(int i, int j, String s, String p, Boolean[][] memo) {
        if (j == p.length()) {
            return i == s.length();
        }
        
        if (memo[i][j] != null) {
            return memo[i][j];
        }
        
        boolean firstMatch = i < s.length() && 
                            (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
        
        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            // Two choices: skip the pattern or use it
            boolean result = dp(i, j + 2, s, p, memo) || // skip "x*"
                            (firstMatch && dp(i + 1, j, s, p, memo)); // use "x*"
            memo[i][j] = result;
            return result;
        } else {
            boolean result = firstMatch && dp(i + 1, j + 1, s, p, memo);
            memo[i][j] = result;
            return result;
        }
    }
    
    // ==================== APPROACH 2: Bottom-Up DP (2D) ====================
    public boolean isMatchDP(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] dp = new boolean[m + 1][n + 1];
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* that can match empty string
        for (int j = 1; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char sc = s.charAt(i - 1);
                char pc = p.charAt(j - 1);
                
                if (pc == '.' || pc == sc) {
                    // Characters match, inherit from diagonal
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pc == '*') {
                    char prev = p.charAt(j - 2);
                    
                    // Match zero: ignore "x*"
                    dp[i][j] = dp[i][j - 2];
                    
                    // Match one or more: if current char matches the pattern
                    if (prev == '.' || prev == sc) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                // If characters don't match and it's not '*', dp[i][j] remains false
            }
        }
        
        return dp[m][n];
    }
    
    // ==================== APPROACH 3: Space Optimized DP ====================
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[] dp = new boolean[n + 1];
        boolean[] prev = new boolean[n + 1];
        
        // Empty string matches empty pattern
        prev[0] = true;
        
        // Handle patterns that can match empty string
        for (int j = 1; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                prev[j] = prev[j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            // Reset dp array for current row
            dp = new boolean[n + 1];
            dp[0] = false; // Non-empty string can't match empty pattern
            
            for (int j = 1; j <= n; j++) {
                char sc = s.charAt(i - 1);
                char pc = p.charAt(j - 1);
                
                if (pc == '.' || pc == sc) {
                    dp[j] = prev[j - 1];
                } else if (pc == '*') {
                    char prevChar = p.charAt(j - 2);
                    
                    // Match zero: skip "x*"
                    dp[j] = dp[j - 2];
                    
                    // Match one or more
                    if (prevChar == '.' || prevChar == sc) {
                        dp[j] = dp[j] || prev[j];
                    }
                }
                // Otherwise dp[j] remains false
            }
            
            // Update prev for next iteration
            prev = dp;
        }
        
        return prev[n];
    }
    
    // ==================== ALTERNATIVE: Greedy Recursive (Simple but may be slow) ====================
    public boolean isMatchGreedy(String s, String p) {
        return isMatchGreedyHelper(s, p, 0, 0);
    }
    
    private boolean isMatchGreedyHelper(String s, String p, int i, int j) {
        if (j == p.length()) return i == s.length();
        
        // Check if first characters match
        boolean firstMatch = i < s.length() && 
                            (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
        
        // If next character is '*'
        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            // Try zero match
            if (isMatchGreedyHelper(s, p, i, j + 2)) return true;
            
            // Try one or more matches
            if (firstMatch && isMatchGreedyHelper(s, p, i + 1, j)) return true;
            
            return false;
        }
        
        // No '*', just match one character
        return firstMatch && isMatchGreedyHelper(s, p, i + 1, j + 1);
    }
    
    // ==================== TESTING ====================
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        System.out.println("=== Testing Regular Expression Matching ===");
        System.out.println();
        
        // Test cases
        String[][] testCases = {
            {"aa", "a"},
            {"aa", "a*"},
            {"ab", ".*"},
            {"aab", "c*a*b"},
            {"mississippi", "mis*is*p*."},
            {"", "a*"},
            {"", ".*"},
            {"ab", ".*c"},
            {"aaa", "a*a"},
            {"aaa", "ab*a*c*a"}
        };
        
        System.out.println("Using Space-Optimized DP (Main Solution):");
        System.out.println("----------------------------------------");
        for (String[] test : testCases) {
            String s = test[0];
            String p = test[1];
            boolean result = sol.isMatch(s, p);
            System.out.printf("isMatch(\"%s\", \"%s\") = %b%n", s, p, result);
        }
        
        System.out.println();
        System.out.println("Using Recursive with Memoization:");
        System.out.println("----------------------------------");
        for (String[] test : testCases) {
            String s = test[0];
            String p = test[1];
            boolean result = sol.isMatchRecursive(s, p);
            System.out.printf("isMatch(\"%s\", \"%s\") = %b%n", s, p, result);
        }
        
        System.out.println();
        System.out.println("Using Bottom-Up DP:");
        System.out.println("--------------------");
        for (String[] test : testCases) {
            String s = test[0];
            String p = test[1];
            boolean result = sol.isMatchDP(s, p);
            System.out.printf("isMatch(\"%s\", \"%s\") = %b%n", s, p, result);
        }
        
        // Additional test cases with explanation
        System.out.println();
        System.out.println("=== Detailed Explanation of Test Cases ===");
        System.out.println("1. \"aa\" vs \"a\"     -> false (needs two 'a's, pattern only matches one)");
        System.out.println("2. \"aa\" vs \"a*\"    -> true  (a* matches zero or more 'a's)");
        System.out.println("3. \"ab\" vs \".*\"    -> true  (.* matches any sequence)");
        System.out.println("4. \"aab\" vs \"c*a*b\" -> true  (c* matches zero, a* matches two, then b)");
        System.out.println("5. \"mississippi\" vs \"mis*is*p*.\" -> false");
        System.out.println("6. \"\" vs \"a*\"       -> true  (a* can match zero characters)");
        System.out.println("7. \"\" vs \".*\"       -> true  (.* can match zero characters)");
        System.out.println("8. \"ab\" vs \".*c\"    -> false (.* consumes everything, no c left)");
        System.out.println("9. \"aaa\" vs \"a*a\"   -> true  (a* matches two a's, then a)");
        System.out.println("10. \"aaa\" vs \"ab*a*c*a\" -> true");
    }
}