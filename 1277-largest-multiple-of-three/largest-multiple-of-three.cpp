class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());

        int sum = 0;
        for (int x : digits)
            sum += x;

        int rem = sum % 3;

        auto removeOne = [&](int r) -> bool {
            for (int i = 0; i < digits.size(); i++) {
                if (digits[i] % 3 == r) {
                    digits.erase(digits.begin() + i);
                    return true;
                }
            }
            return false;
        };

        auto removeTwo = [&](int r) -> bool {
            int removed = 0;

            for (int i = 0; i < digits.size() && removed < 2;) {
                if (digits[i] % 3 == r) {
                    digits.erase(digits.begin() + i);
                    removed++;
                } else {
                    i++;
                }
            }

            return removed == 2;
        };

        if (rem == 1) {
            if (!removeOne(1)) {
                removeTwo(2);
            }
        }
        else if (rem == 2) {
            if (!removeOne(2)) {
                removeTwo(1);
            }
        }

        if (digits.empty())
            return "";

        sort(digits.rbegin(), digits.rend());

        // If the largest digit is 0, all digits are zero.
        if (digits[0] == 0)
            return "0";

        string ans;
        for (int x : digits)
            ans += char('0' + x);

        return ans;
    }
};