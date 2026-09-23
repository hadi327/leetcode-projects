class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(100, 0);
        int ans = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int x = i;
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            boxes[sum]++;
            ans = max(ans, boxes[sum]);
        }

        return ans;
    }
};