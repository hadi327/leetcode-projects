class Solution:
    def smallestPalindrome(self,s):
        count = [0] * 26

        # Count frequency of each character
        for ch in s:
            count[ord(ch) - ord('a')] += 1

        left = []
        middle = ""

        # Build left half and find middle character
        for i in range(26):
            left.append(chr(i + ord('a')) * (count[i] // 2))
            if count[i] % 2 == 1:
                middle = chr(i + ord('a'))

        left = "".join(left)
        right = left[::-1]

        return left + middle + right