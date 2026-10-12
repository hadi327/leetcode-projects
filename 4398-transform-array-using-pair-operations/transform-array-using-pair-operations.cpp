
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum = 0;

        for (int x : source) {
            sum += x;
        }

        for (int x : target) {
            sum -= x;
        }

        return sum == 0;
    }
};
