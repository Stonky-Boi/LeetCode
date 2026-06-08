class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        for(int n:nums){
            if(n>0)seen.insert(n);
        }
        return seen.size();
    }
};