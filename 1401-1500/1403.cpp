class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int sum=0;
        for(int n:nums)sum+=n;
        vector<int> answer;
        int curr=0;
        for(int n:nums){
            answer.push_back(n);
            curr+=n;
            if(curr>sum-curr)break;
        }
        return answer;
    }
};