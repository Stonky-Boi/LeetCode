class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> seen(nums.begin(),nums.end());
        while(seen.count(original))original*=2;
        return original;
    }
};