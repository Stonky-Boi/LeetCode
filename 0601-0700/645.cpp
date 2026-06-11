class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        vector<int> ans(2,0);
        int sum=n*(n+1)/2;
        int sqsum=n*(n+1)*(2*n+1)/6;
        int real_sum=0,real_sqsum=0;
        for(int i:nums){
            real_sum+=i;
            real_sqsum+=1ll*i*i;
        }
        int diff=real_sum-sum;
        int sqdiff=real_sqsum-sqsum;
        int value=sqdiff/diff;
        ans[0]=(value+diff)/2;
        ans[1]=(value-diff)/2;
        return ans;
    }
};