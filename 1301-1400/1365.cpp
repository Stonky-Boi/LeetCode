class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101,0);
        for(int i:nums)count[i]++;
        for(int i=1;i<=100;i++)count[i]+=count[i-1];
        vector<int> answer(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)answer[i]=0;
            else answer[i]=count[nums[i]-1];
        }
        return answer;
    }
};