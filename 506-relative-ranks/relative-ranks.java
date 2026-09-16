class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;

        Integer[] indices = new Integer[n];

        for (int i = 0; i < n; i++)
            indices[i] = i;

        Arrays.sort(indices,
            (a, b) -> Integer.compare(score[b], score[a]));

        String[] result = new String[n];

        for (int i = 0; i < n; i++) {
            if (i == 0)
                result[indices[i]] = "Gold Medal";
            else if (i == 1)
                result[indices[i]] = "Silver Medal";
            else if (i == 2)
                result[indices[i]] = "Bronze Medal";
            else
                result[indices[i]] = String.valueOf(i + 1);
        }

        return result;
    }
}