class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=n-k;i--)sum+=nums[i];
        for(int i=0;i<k;i++)sum-=nums[i];
        return sum;
    }
};