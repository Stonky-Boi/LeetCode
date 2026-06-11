class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int,greater<int>> num(nums.begin(),nums.end());
        vector<int> answer;
        for(int n:num){
            if(k==0)break;
            answer.push_back(n);
            k--;
        }
        return answer;
    }
};