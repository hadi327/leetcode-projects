public class Solution {
    public string RemoveStars(string s) {
      Stack<char> stack = new Stack<char>();

        foreach (char c in s) {
            if (c == '*') {
                stack.Pop();
            } else {
                stack.Push(c);
            }
        }

        char[] result = stack.ToArray();
        Array.Reverse(result);

        return new string(result);  
    }
}