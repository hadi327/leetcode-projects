class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        int[] a = parse(num1);
        int[] b = parse(num2);

        int real = a[0] * b[0] - a[1] * b[1];
        int imaginary = a[0] * b[1] + a[1] * b[0];

        return real + "+" + imaginary + "i";
    }

    private int[] parse(String s) {
        int plus = s.indexOf('+');

        int real = Integer.parseInt(
            s.substring(0, plus)
        );

        int imaginary = Integer.parseInt(
            s.substring(plus + 1, s.length() - 1)
        );

        return new int[]{real, imaginary};
    }
}