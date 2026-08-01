#include <string>
#include <algorithm>

class Solution {
public:
    int minFlips(std::string s) {
        int n = s.length();
        int diff1 = 0, diff2 = 0;
        int ans = 1e9;

        int left = 0;
        for (int right = 0; right < 2 * n; ++right) {
            char c = s[right % n];
            char t1 = (right % 2 == 0) ? '0' : '1';
            
            if (c != t1) diff1++;
            else diff2++;

            if (right - left + 1 == n) {
                ans = std::min({ans, diff1, diff2});

                char left_c = s[left % n];
                char left_t1 = (left % 2 == 0) ? '0' : '1';
                if (left_c != left_t1) diff1--;
                else diff2--;

                left++;
            }
        }

        return ans;
    }
};