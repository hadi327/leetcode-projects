class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
            return 0;

        int index = 0;
        int count1 = 0;
        int count2 = 0;

        unordered_map<int, pair<int, int>> seen;

        while (count1 < n1) {
            for (char c : s1) {
                if (c == s2[index]) {
                    index++;

                    if (index == s2.size()) {
                        index = 0;
                        count2++;
                    }
                }
            }

            count1++;

            if (seen.count(index)) {
                int prevCount1 = seen[index].first;
                int prevCount2 = seen[index].second;

                int cycle1 = count1 - prevCount1;
                int cycle2 = count2 - prevCount2;

                int remaining = n1 - count1;
                int cycles = remaining / cycle1;

                count1 += cycles * cycle1;
                count2 += cycles * cycle2;
            } else {
                seen[index] = {count1, count2};
            }
        }

        return count2 / n2;
    }
};