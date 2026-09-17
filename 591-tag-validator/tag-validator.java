class Solution {
    public boolean isValid(String code) {
        Stack<String> stack = new Stack<>();
        int n = code.length();
        int i = 0;

        while (i < n) {
            if (i > 0 && stack.isEmpty())
                return false;

            if (code.startsWith("<![CDATA[", i)) {
                if (stack.isEmpty())
                    return false;

                int end = code.indexOf("]]>", i + 9);

                if (end == -1)
                    return false;

                i = end + 3;

            } else if (code.startsWith("</", i)) {
                int end = code.indexOf('>', i + 2);

                if (end == -1)
                    return false;

                String tag = code.substring(i + 2, end);

                if (!isValidTag(tag))
                    return false;

                if (stack.isEmpty() ||
                    !stack.pop().equals(tag)) {
                    return false;
                }

                i = end + 1;

            } else if (code.charAt(i) == '<') {
                int end = code.indexOf('>', i + 1);

                if (end == -1)
                    return false;

                String tag = code.substring(i + 1, end);

                if (!isValidTag(tag))
                    return false;

                stack.push(tag);
                i = end + 1;

            } else {
                i++;
            }
        }

        return stack.isEmpty();
    }

    private boolean isValidTag(String tag) {
        if (tag.length() < 1 || tag.length() > 9)
            return false;

        for (char c : tag.toCharArray()) {
            if (c < 'A' || c > 'Z')
                return false;
        }

        return true;
    }
}