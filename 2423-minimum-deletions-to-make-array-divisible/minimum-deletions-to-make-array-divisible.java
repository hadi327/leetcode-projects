class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        int totalGCD = numsDivide[0];
        for (int i = 1; i < numsDivide.length; i++) {
            totalGCD = solve(totalGCD, numsDivide[i]);
        }
        System.out.println("GCD = "+totalGCD);
        int c = 0 ;
        Arrays.sort(nums);
        int n = nums.length;
        for(int i = 0 ; i < n ; i++){
            if(totalGCD%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
    int solve(int a , int b ){
        while(b!=0){
            int t = b ;
            b = a%b;
            a = t;
        }
        return  a;
    }
}