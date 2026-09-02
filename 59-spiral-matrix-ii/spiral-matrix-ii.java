class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while (top <= bottom && left <= right) {

            // Top
            for (int j = left; j <= right; j++)
                matrix[top][j] = num++;

            top++;

            // Right
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = num++;

            right--;

            // Bottom
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    matrix[bottom][j] = num++;

                bottom--;
            }

            // Left
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = num++;

                left++;
            }
        }

        return matrix;
    }
}