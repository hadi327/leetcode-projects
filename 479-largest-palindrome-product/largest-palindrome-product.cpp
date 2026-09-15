class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);

        for (long long left = upper; left >= lower; left--) {
            string s = to_string(left);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long palindrome =
                stoll(s + rev);

            for (long long x = upper; x * x >= palindrome; x--) {
                if (palindrome % x == 0)
                    return palindrome % 1337;
            }
        }

        return -1;
    }
};