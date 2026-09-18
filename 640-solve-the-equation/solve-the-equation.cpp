class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=');

        auto left = parse(equation.substr(0, pos));
        auto right = parse(equation.substr(pos + 1));

        int coefficient = left.first - right.first;
        int constant = right.second - left.second;

        if (coefficient == 0) {
            if (constant == 0)
                return "Infinite solutions";

            return "No solution";
        }

        return "x=" + to_string(constant / coefficient);
    }

private:
    pair<int, int> parse(string s) {
        int coefficient = 0;
        int constant = 0;

        int i = 0;
        int sign = 1;

        while (i < s.size()) {
            if (s[i] == '+') {
                sign = 1;
                i++;
            }
            else if (s[i] == '-') {
                sign = -1;
                i++;
            }

            int number = 0;
            bool hasNumber = false;

            while (i < s.size() &&
                   isdigit(s[i])) {
                number = number * 10 +
                         (s[i] - '0');

                i++;
                hasNumber = true;
            }

            if (i < s.size() && s[i] == 'x') {
                coefficient +=
                    sign * (hasNumber ? number : 1);

                i++;
            }
            else {
                constant +=
                    sign * number;
            }
        }

        return {coefficient, constant};
    }
};