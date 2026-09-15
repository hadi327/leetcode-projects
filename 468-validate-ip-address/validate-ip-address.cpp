
#include <string>
#include <cctype>

class Solution {
public:
    std::string validIPAddress(std::string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        if (isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

private:
    // Exactly 4 groups separated by '.', each 0-255, no leading zeros.
    bool isIPv4(const std::string& s) {
        const int n = static_cast<int>(s.size());
        int parts = 0;
        int i = 0;

        while (i < n) {
            int start = i;
            int value = 0;
            int len = 0;

            while (i < n && s[i] != '.') {
                if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
                value = value * 10 + (s[i] - '0');
                ++i;
                ++len;
                if (len > 3) return false;          // group too long
            }

            if (len == 0) return false;              // empty group ("..", leading/trailing '.')
            if (len > 1 && s[start] == '0') return false;  // leading zero
            if (value > 255) return false;

            ++parts;
            if (parts > 4) return false;

            if (i < n) {                             // consume '.'
                ++i;
                if (i == n) return false;            // trailing '.'
            }
        }

        return parts == 4;
    }

    // Exactly 8 groups separated by ':', each 1-4 hex digits.
    bool isIPv6(const std::string& s) {
        const int n = static_cast<int>(s.size());
        int parts = 0;
        int i = 0;

        while (i < n) {
            int len = 0;

            while (i < n && s[i] != ':') {
                char c = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
                bool isHex = std::isdigit(static_cast<unsigned char>(c)) ||
                             (c >= 'a' && c <= 'f');
                if (!isHex) return false;
                ++i;
                ++len;
                if (len > 4) return false;           // group too long
            }

            if (len == 0) return false;              // empty group ("::", leading/trailing ':')

            ++parts;
            if (parts > 8) return false;

            if (i < n) {                             // consume ':'
                ++i;
                if (i == n) return false;            // trailing ':'
            }
        }

        return parts == 8;
    }
};