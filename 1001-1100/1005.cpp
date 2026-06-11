class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min_value=INT_MAX,sum=0;
        for(int n:nums){
            if(n<0 && k>0){
                n=-n;
                k--;
            }
            min_value=min(min_value,n);
            sum+=n;
        }
        if(k%2==1)sum-=2*min_value;
        return sum;
    }
};