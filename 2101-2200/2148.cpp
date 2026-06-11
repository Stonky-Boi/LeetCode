class Solution {
public:
    int countElements(vector<int>& nums) {
        int min_val=INT_MAX,max_val=INT_MIN;
        for(int n:nums){
            min_val=min(min_val,n);
            max_val=max(max_val,n);
        }
        int count=0;
        for(int n:nums){
            if(n>min_val&&n<max_val)count++;
        }
        return count;
    }
};