public class Solution {
    public string DecodeString(string s) {
         Stack<int> countStack = new Stack<int>();
        Stack<string> stringStack = new Stack<string>();

        int num = 0;
        string current = "";

        foreach (char c in s) {
            if (char.IsDigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.Push(num);
                stringStack.Push(current);

                num = 0;
                current = "";
            }
            else if (c == ']') {
                int repeat = countStack.Pop();
                string previous = stringStack.Pop();

                current = previous + string.Concat(Enumerable.Repeat(current, repeat));
            }
            else {
                current += c;
            }
        }

        return current;  
    }
}