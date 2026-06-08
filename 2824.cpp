class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int pairs=0;
        while(l<r){
            if(nums[l]+nums[r]<target){
                pairs+=r-l;
                l++;
            }
            else r--;
        }
        return pairs;
    }
};