class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even=0;
        for(int n:nums){
            if(n%2==0)even++;
        }
        for(int i=0;i<even;i++)nums[i]=0;
        for(int i=even;i<nums.size();i++)nums[i]=1;
        return nums;
    }
};