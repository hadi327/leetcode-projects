class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n=nums.size();
        int bs=0;
        for(int i=0;i<n-1;i++){
            bs+= abs(nums[i]-nums[i+1]);
        }
        int max_gain=0;
        for(int i=0;i<n-1;++i){
            int gsz= abs(nums[0]-nums[i+1]) - abs(nums[i]-nums[i+1]);
            int gel= abs(nums[n-1]-nums[i]) - abs(nums[i]-nums[i+1]);
            max_gain= max({max_gain, gsz, gel});
        }
        int max_of_mins= INT_MIN;
        int min_of_max= INT_MAX;
        for(int i=0;i<n-1;++i){
            int cmin= min(nums[i],nums[i+1]);
            int cmax= max(nums[i],nums[i+1]);
            max_of_mins= max(max_of_mins,cmin);
            min_of_max= min(min_of_max,cmax);
        }
        if(max_of_mins>min_of_max){
            int ig= 2*(max_of_mins- min_of_max);
            max_gain= max(max_gain,ig);

        }
        return bs+ max_gain;
    }
};