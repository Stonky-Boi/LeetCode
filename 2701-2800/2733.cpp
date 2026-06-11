class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int max_val=INT_MIN,min_val=INT_MAX;
        for(int n:nums){
            max_val=max(max_val,n);
            min_val=min(min_val,n);
        }
        for(int n:nums){
            if(n!=max_val &&n!=min_val)return n;
        }
        return -1;
    }
};