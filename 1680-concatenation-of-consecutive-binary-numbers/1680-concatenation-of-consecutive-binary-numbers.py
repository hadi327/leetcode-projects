class Solution(object):
    def concatenatedBinary(self, n):
        MOD = 10**9 + 7
        result = 0
        bit_length = 0
        
        for i in range(1, n + 1):
            # Check if i is a power of 2 (e.g., 1, 2, 4, 8, 16...)
            # When it is, the number of binary digits increases by 1
            if (i & (i - 1)) == 0:
                bit_length += 1
            
            # Shift the result left by bit_length and add i, then take modulo
            result = ((result << bit_length) + i) % MOD
            
        return result
        