class Solution {
    private Map<String, List<String>> memo = new HashMap<>();

    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s, new HashSet<>(wordDict));
    }

    private List<String> dfs(String s, Set<String> dict) {
        if (memo.containsKey(s))
            return memo.get(s);

        List<String> result = new ArrayList<>();

        if (s.isEmpty()) {
            result.add("");
            return result;
        }

        for (String word : dict) {
            if (s.startsWith(word)) {
                List<String> suffixes =
                    dfs(s.substring(word.length()), dict);

                for (String suffix : suffixes) {
                    result.add(
                        word + (suffix.isEmpty() ? "" : " " + suffix)
                    );
                }
            }
        }

        memo.put(s, result);
        return result;
    }
}