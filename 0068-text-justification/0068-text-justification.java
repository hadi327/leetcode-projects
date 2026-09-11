import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {

        List<String> result = new ArrayList<>();

        int i = 0;

        while (i < words.length) {

            int j = i;
            int lineLength = 0;

            // Find how many words fit
            while (j < words.length &&
                   lineLength + words[j].length() + (j - i) <= maxWidth) {

                lineLength += words[j].length();
                j++;
            }

            int wordCount = j - i;
            int spaces = maxWidth - lineLength;

            StringBuilder line = new StringBuilder();

            // Last line OR line with one word
            if (j == words.length || wordCount == 1) {

                for (int k = i; k < j; k++) {

                    line.append(words[k]);

                    if (k < j - 1)
                        line.append(" ");
                }

                while (line.length() < maxWidth)
                    line.append(" ");

            } 
            else {

                int gaps = wordCount - 1;

                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {

                    line.append(words[k]);

                    if (k < j - 1) {

                        int count = spaceEach;

                        if (k - i < extra)
                            count++;

                        line.append(" ".repeat(count));
                    }
                }
            }

            result.add(line.toString());

            i = j;
        }

        return result;
    }
}