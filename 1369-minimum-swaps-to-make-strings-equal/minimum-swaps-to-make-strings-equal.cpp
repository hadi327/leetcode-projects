class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0;
        int yx = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i])
                continue;

            if (s1[i] == 'x' && s2[i] == 'y')
                xy++;
            else
                yx++;
        }

        // Odd number of mismatches is impossible
        if ((xy + yx) % 2 != 0)
            return -1;

        int swaps = xy / 2 + yx / 2;

        // One xy and one yx remain
        if (xy % 2 == 1)
            swaps += 2;

        return swaps;
    }
};