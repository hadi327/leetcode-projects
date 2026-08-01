class Solution(object):
    def minOperations(self, s):
        flips_for_pattern0 = 0
        n = len(s)
        
        for i, char in enumerate(s):
            # Pattern 0 expects '0' at even indices and '1' at odd indices
            expected_char = '0' if i % 2 == 0 else '1'
            if char != expected_char:
                flips_for_pattern0 += 1
        
        # Flips for Pattern 1 is simply (n - flips_for_pattern0)
        return min(flips_for_pattern0, n - flips_for_pattern0)
        