class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> average;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            double avg=(nums[l++]+nums[r--])/2.0;
            average.insert(avg);
        }
        return average.size();
    }
};