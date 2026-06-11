class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> index(n);
        for(int i=0;i<n;i++)index[i]={nums[i],i};
        sort(index.rbegin(),index.rend());
        vector<pair<int,int>> topk(index.begin(),index.begin()+k);
        sort(topk.begin(),topk.end(),[](auto& a,auto& b){return a.second<b.second;});
        vector<int> answer;
        for(auto& [i,_]:topk)answer.push_back(i);
        return answer;
    }
};