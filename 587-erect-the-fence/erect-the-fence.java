class Solution {
    public int[][] outerTrees(int[][] trees) {
        if (trees.length <= 1)
            return trees;

        Arrays.sort(trees, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        List<int[]> hull = new ArrayList<>();

        // Lower hull
        for (int[] tree : trees) {
            while (hull.size() >= 2 &&
                   cross(hull.get(hull.size() - 2),
                         hull.get(hull.size() - 1),
                         tree) < 0) {
                hull.remove(hull.size() - 1);
            }
            hull.add(tree);
        }

        int lowerSize = hull.size();

        // Upper hull
        for (int i = trees.length - 2; i >= 0; i--) {
            int[] tree = trees[i];

            while (hull.size() > lowerSize &&
                   cross(hull.get(hull.size() - 2),
                         hull.get(hull.size() - 1),
                         tree) < 0) {
                hull.remove(hull.size() - 1);
            }

            hull.add(tree);
        }

        Set<String> seen = new HashSet<>();
        List<int[]> result = new ArrayList<>();

        for (int[] point : hull) {
            String key = point[0] + "," + point[1];

            if (seen.add(key))
                result.add(point);
        }

        return result.toArray(new int[result.size()][]);
    }

    private long cross(int[] a, int[] b, int[] c) {
        return (long) (b[0] - a[0]) * (c[1] - a[1])
             - (long) (b[1] - a[1]) * (c[0] - a[0]);
    }
}