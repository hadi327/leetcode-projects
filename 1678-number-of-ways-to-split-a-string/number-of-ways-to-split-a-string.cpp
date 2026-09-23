class Solution {
public:
    int numWays(string s) {
        long ones = 0, n = s.size(), mod = 1e9+7;
        for(int i = 0; i < n; i++)
            if(s[i] == '1') ones++;//caculating the no. of ones
        //CASE 1
        if(ones%3 != 0) return 0;

        //CASE 2
        if(ones == 0) return (int)(((n-1)*(n-2)/2)%mod);

        //CASE 3
        //firstOneThird(2 ones) is the no.of ones required for s1,s2 and s3
        long firstOneThird = ones/3, secondOneThird = 2*firstOneThird;
        ones = 0;//reseting ones to zero because now we are traversing the string again 
        long firstway = 0, secondway = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ones++;
            //Now, no. of ones has become 2 (has reached index 3) 
            //    2 == 2     Now, firstway is calculating the combinations for s1
            if(ones == firstOneThird) firstway++; 

            //Now, no. of ones has become 4 (has reached index 9)
            //   4 == 4     Now, secondway is calculating the combinations for s2
            if(ones == secondOneThird) secondway++;
        }
        return (int)((firstway * secondway)%mod);
    }
};