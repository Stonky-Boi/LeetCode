class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int i:nums)freq[i]++;
        int total=n*(n-1)*(n-2)/6;
        int invalid=0;
        for(auto& [_,f]:freq){
            if(f>=3)invalid+=f*(f-1)*(f-2)/6;
            if(f>=2)invalid+=f*(f-1)*(n-f)/2;
        }
        return total-invalid;
    }
};