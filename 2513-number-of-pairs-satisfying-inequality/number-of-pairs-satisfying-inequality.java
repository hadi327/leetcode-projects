
class Solution {
    private long count = 0;

    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        int n = nums1.length;
        long[] arr = new long[n];

        for (int i = 0; i < n; i++) {
            arr[i] = (long) nums1[i] - nums2[i];
        }

        long[] temp = new long[n];
        mergeSort(arr, temp, 0, n - 1, diff);

        return count;
    }

    private void mergeSort(long[] arr, long[] temp,
                           int left, int right, int diff) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid, diff);
        mergeSort(arr, temp, mid + 1, right, diff);

        // Count valid pairs across the two halves
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right &&
                   arr[j] < arr[i] - (long) diff) {
                j++;
            }

            count += right - j + 1L;
        }

        // Merge the sorted halves
        int i = left;
        j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
    }
}
