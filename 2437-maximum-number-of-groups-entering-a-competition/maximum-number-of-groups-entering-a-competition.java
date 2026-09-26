class Solution {
    public int maximumGroups(int[] grades) {
        int n = grades.length;

        int groups = 0;
        int studentsUsed = 0;
        int nextSize = 1;

        while (studentsUsed + nextSize <= n) {
            studentsUsed += nextSize;
            groups++;
            nextSize++;
        }

        return groups;
    }
}