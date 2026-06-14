class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        __int128 total=1;
        for(int j:nums)total*=j;
        if(total!=(__int128)target*target)return false;
        int masks=1<<n;
        for(int i=1;i<masks-1;i++){
            long long product=1;
            bool valid=true;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    if(product>target/nums[j]){
                        valid=false;
                        break;
                    }
                    product*=nums[j];
                }
            }
            if(valid &&product==target)return true;
        }
        return false;
    }
};