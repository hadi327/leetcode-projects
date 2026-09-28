class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        long maxVol = (long) Math.pow(10, 9);
        long maxDim = (long) Math.pow(10, 4);

        long volume = (long) length * width * height;
        boolean isBulky = (volume >= maxVol) || (length >= maxDim) || (width >= maxDim) || (height >= maxDim);
        boolean isHeavy = (mass >= 100);

        if (isBulky && isHeavy) {
            return "Both";
        }
        if (isBulky && !isHeavy) {
            return "Bulky";
        }
        if (!isBulky && isHeavy) {
            return "Heavy";
        }

        return "Neither";
    }
}