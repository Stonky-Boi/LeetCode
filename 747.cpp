class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int first=INT_MIN,second=INT_MIN;
        int index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                second=first;
                first=nums[i];
                index=i;
            }
            else if(nums[i]>second)second=nums[i];
        }
        return first>=2*second?index:-1;
    }
};