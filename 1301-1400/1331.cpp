class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return {};
        int n=arr.size();
        vector<pair<int,int>> rank(n);
        for(int i=0;i<n;i++)rank[i]={arr[i],i};
        sort(rank.begin(),rank.end());
        vector<int> answer(n);
        int curr_rank=1;
        answer[rank[0].second]=curr_rank;
        for(int i=1;i<n;i++){
            if(rank[i].first!=rank[i-1].first)curr_rank++;
            answer[rank[i].second]=curr_rank;
        }
        return answer;
    }
};