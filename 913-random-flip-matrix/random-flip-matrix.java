class Solution {
    int rows, cols;
    int total;
    Random random = new Random();
    Map<Integer, Integer> map = new HashMap<>();

    public Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
    }

    public int[] flip() {
        int randomIndex = random.nextInt(total);

        int index = map.getOrDefault(randomIndex, randomIndex);

        total--;

        map.put(randomIndex,
                map.getOrDefault(total, total));

        return new int[]{index / cols, index % cols};
    }

    public void reset() {
        total = rows * cols;
        map.clear();
    }
}