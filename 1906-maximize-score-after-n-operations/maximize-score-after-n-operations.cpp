class Solution {
public:

    int helper(int a,int m, vector<int>& nums,unordered_map<int,int>& mp){

        if(m == 0)
        return 0;

        int key = a+m*10;


         if(mp.find(key) != mp.end())
         return mp[key];

         int maxVal = 0;

         for(int i=0;i<nums.size();i++){
             if(m & (1<<i))
             for(int j=i+1;j<nums.size();j++){
                  if(m & (1<<j))
                   maxVal = max(maxVal,a*__gcd(nums[i],nums[j]) + helper(a+1,m^(1<<i)^(1<<j),nums,mp));
             }
               
         }

         return mp[key]=maxVal; 
    }
    int maxScore(vector<int>& nums) {

         unordered_map<int,int> mp;

         return helper(1,(1<<nums.size())-1,nums,mp);
    }
};