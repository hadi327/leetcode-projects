#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases where zigzagging is impossible
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(std::min(static_cast<int>(s.length()), numRows));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            
            // Reverse direction if we touch the top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currRow += goingDown ? 1 : -1;
        }

        // Concatenate all row strings
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};