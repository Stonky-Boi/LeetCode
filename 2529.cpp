class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int negative=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int positive=upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        positive=n-positive;
        return max(positive,negative);
    }
};