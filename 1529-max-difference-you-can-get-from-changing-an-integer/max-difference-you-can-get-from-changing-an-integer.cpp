class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Maximum value
        string mx = s;

        char change = 0;
        for (char c : mx) {
            if (c != '9') {
                change = c;
                break;
            }
        }

        if (change) {
            for (char &c : mx) {
                if (c == change)
                    c = '9';
            }
        }

        // Minimum value
        string mn = s;

        if (mn[0] != '1') {
            char change = mn[0];

            for (char &c : mn) {
                if (c == change)
                    c = '1';
            }
        } else {
            char change = 0;

            for (int i = 1; i < mn.size(); i++) {
                if (mn[i] != '0' && mn[i] != '1') {
                    change = mn[i];
                    break;
                }
            }

            if (change) {
                for (char &c : mn) {
                    if (c == change)
                        c = '0';
                }
            }
        }

        return stoi(mx) - stoi(mn);
    }
};