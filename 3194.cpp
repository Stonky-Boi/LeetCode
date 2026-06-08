class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double min_avg=DBL_MAX;
        int l=0,r=nums.size()-1;
        while(l<r){
            double avg=(nums[l++]+nums[r--])/2.0;
            min_avg=min(min_avg,avg);
        }
        return min_avg;
    }
};