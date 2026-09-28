class Solution {
    static final long MOD = 1_000_000_007L;

    public int countAnagrams(String s) {
        String[] words = s.split(" ");

        int maxLen = 0;
        for (String word : words) {
            maxLen = Math.max(maxLen, word.length());
        }

        long[] fact = new long[maxLen + 1];
        long[] invFact = new long[maxLen + 1];

        fact[0] = 1;

        for (int i = 1; i <= maxLen; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[maxLen] = modPow(fact[maxLen], MOD - 2);

        for (int i = maxLen; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        long answer = 1;

        for (String word : words) {
            int[] freq = new int[26];

            for (char c : word.toCharArray()) {
                freq[c - 'a']++;
            }

            long ways = fact[word.length()];

            for (int count : freq) {
                ways = ways * invFact[count] % MOD;
            }

            answer = answer * ways % MOD;
        }

        return (int) answer;
    }

    private long modPow(long base, long exp) {
        long result = 1;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exp >>= 1;
        }

        return result;
    }
}