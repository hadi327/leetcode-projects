class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        unsigned int n = num;
        string hex = "0123456789abcdef";
        string result;

        while (n > 0) {
            result.push_back(hex[n & 15]);
            n >>= 4;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};