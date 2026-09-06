class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord,
                                          List<String> wordList) {
        Set<String> words = new HashSet<>(wordList);
        List<List<String>> ans = new ArrayList<>();

        if (!words.contains(endWord)) return ans;

        Map<String, List<String>> parents = new HashMap<>();
        Set<String> current = new HashSet<>();
        current.add(beginWord);

        boolean found = false;

        while (!current.isEmpty() && !found) {
            words.removeAll(current);
            Set<String> next = new HashSet<>();

            for (String word : current) {
                char[] chars = word.toCharArray();

                for (int i = 0; i < chars.length; i++) {
                    char original = chars[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        chars[i] = c;
                        String newWord = new String(chars);

                        if (words.contains(newWord)) {
                            next.add(newWord);

                            parents
                                .computeIfAbsent(newWord, k -> new ArrayList<>())
                                .add(word);

                            if (newWord.equals(endWord))
                                found = true;
                        }
                    }

                    chars[i] = original;
                }
            }

            current = next;
        }

        if (found) {
            List<String> path = new ArrayList<>();
            path.add(endWord);
            build(endWord, beginWord, parents, path, ans);
        }

        return ans;
    }

    private void build(String word, String beginWord,
                       Map<String, List<String>> parents,
                       List<String> path,
                       List<List<String>> ans) {

        if (word.equals(beginWord)) {
            List<String> copy = new ArrayList<>(path);
            Collections.reverse(copy);
            ans.add(copy);
            return;
        }

        if (!parents.containsKey(word)) return;

        for (String parent : parents.get(word)) {
            path.add(parent);
            build(parent, beginWord, parents, path, ans);
            path.remove(path.size() - 1);
        }
    }
}