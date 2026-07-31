class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26

        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        freq.sort(reverse=True)

        ans = 0
        for i, f in enumerate(freq):
            ans += f * (i // 8 + 1)

        return ans
        