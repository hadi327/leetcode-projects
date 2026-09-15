class Solution {
public:
    long long mergeSort(vector<int>& nums,
                        vector<int>& temp,
                        int left,
                        int right) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        long long result = 0;

        result += mergeSort(nums, temp, left, mid);
        result += mergeSort(nums, temp, mid + 1, right);

        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            result += j - (mid + 1);
        }

        int i = left;
        j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        for (int x = left; x <= right; x++)
            nums[x] = temp[x];

        return result;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());

        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};