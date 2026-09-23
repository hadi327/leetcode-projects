class Solution {
public:
    long long calcSum(long long peak, long long len) {
        // Sum of the decreasing sequence:
        // peak, peak-1, ..., peak-len+1
        if (peak >= len) {
            return (peak + (peak - len + 1)) * len / 2;
        }

        // We reach 1 before using all len positions.
        // Remaining positions must be 1.
        return peak * (peak + 1) / 2 + (len - peak);
    }

    int maxValue(int n, int index, int maxSum) {
        long long left = 1;
        long long right = maxSum;

        while (left < right) {
            long long mid = (left + right + 1) / 2;

            long long leftSum = calcSum(mid - 1, index);
            long long rightSum = calcSum(mid - 1, n - index - 1);

            long long total = leftSum + mid + rightSum;

            if (total <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};