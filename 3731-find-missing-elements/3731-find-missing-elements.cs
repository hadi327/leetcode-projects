public class Solution {
    public IList<int> FindMissingElements(int[] nums) {
         int min = int.MaxValue;
        int max = int.MinValue;

        HashSet<int> set = new HashSet<int>();

        foreach (int num in nums) {
            min = Math.Min(min, num);
            max = Math.Max(max, num);
            set.Add(num);
        }

        IList<int> result = new List<int>();

        for (int i = min + 1; i < max; i++) {
            if (!set.Contains(i)) {
                result.Add(i);
            }
        }

        return result;
    }
}