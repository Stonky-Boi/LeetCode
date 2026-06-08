class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int x=1;x<=n;x++){
            int i=n-x;
            if(nums[i]>=x &&(i==0||nums[i-1]<x))return x;
        }
        return -1;
    }
};