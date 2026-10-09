
class TextEditor {
    private StringBuilder left;
    private StringBuilder right;

    public TextEditor() {
        left = new StringBuilder();
        right = new StringBuilder();
    }

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        int deleted = Math.min(k, left.length());
        left.delete(left.length() - deleted, left.length());
        return deleted;
    }

    public String cursorLeft(int k) {
        while (k > 0 && left.length() > 0) {
            char ch = left.charAt(left.length() - 1);
            left.deleteCharAt(left.length() - 1);
            right.append(ch);
            k--;
        }

        return getText();
    }

    public String cursorRight(int k) {
        while (k > 0 && right.length() > 0) {
            char ch = right.charAt(right.length() - 1);
            right.deleteCharAt(right.length() - 1);
            left.append(ch);
            k--;
        }

        return getText();
    }

    private String getText() {
        int start = Math.max(0, left.length() - 10);
        return left.substring(start);
    }
}
