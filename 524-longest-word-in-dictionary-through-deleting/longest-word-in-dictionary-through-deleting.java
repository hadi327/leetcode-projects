class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        String result = "";

        for (String word : dictionary) {
            if (isSubsequence(word, s)) {
                if (word.length() > result.length() ||
                    (word.length() == result.length() &&
                     word.compareTo(result) < 0)) {
                    result = word;
                }
            }
        }

        return result;
    }

    private boolean isSubsequence(String word, String s) {
        int i = 0;

        for (int j = 0; j < s.length() && i < word.length(); j++) {
            if (word.charAt(i) == s.charAt(j))
                i++;
        }

        return i == word.length();
    }
}