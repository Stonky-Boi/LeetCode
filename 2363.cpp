class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ret;
        map<int,int> weight;
        for(auto& i:items1){
            if(weight.count(i[0]))weight[i[0]]+=i[1];
            else weight[i[0]]=i[1];
        }
        for(auto& i:items2){
            if(weight.count(i[0]))weight[i[0]]+=i[1];
            else weight[i[0]]=i[1];
        }
        for(auto [v,w]:weight)ret.push_back({v,w});
        return ret;
    }
};