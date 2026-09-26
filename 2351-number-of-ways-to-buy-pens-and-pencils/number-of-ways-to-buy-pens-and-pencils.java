class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long res = 0;
        int pens = 0;
        while(pens*cost1 <= total)
        {
            res += (total-(pens*cost1))/cost2+1;
            pens++;
        }
        return res;
    }
}