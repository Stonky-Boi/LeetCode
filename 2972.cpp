class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l+1<n &&nums[l]<nums[l+1])l++;
        if(l==n-1)return 1ll*n*(n+1)/2;
        while(r-1>=0 &&nums[r-1]<nums[r])r--;
        long long count=(l+1)+(n-r)+1;
        for(int i=0;i<=l;i++){
            while(r<n &&nums[r]<=nums[i])r++;
            count+=n-r;
        }
        return count;
    }
};