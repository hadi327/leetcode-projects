class Solution(object):
    def minimumPushes(self, word):
        freq = {}
        for ch in word:
            freq[ch] = freq.get(ch, 0) + 1
        
        # Sort by frequency descending
        sorted_freq = sorted(freq.values(), reverse=True)
        
        total = 0
        for i, count in enumerate(sorted_freq):
            # Each key can have at most 8 letters in first position
            # Next 8 in second position, etc.
            key_cycle = i // 8 + 1
            total += count * key_cycle
        
        return total
        