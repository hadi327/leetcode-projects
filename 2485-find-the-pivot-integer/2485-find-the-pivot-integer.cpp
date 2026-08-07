class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int root = sqrt(total);

        return (root * root == total) ? root : -1;
    }
};