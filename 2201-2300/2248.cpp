class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> freq;
        int n=nums.size();
        for(auto& i:nums){
            for(int n:i)freq[n]++;
        }
        vector<int> answer;
        for(auto& [value,frequency]:freq){
            if(frequency==n)answer.push_back(value);
        }
        return answer;
    }
};