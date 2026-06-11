class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int answer=0;
        for(auto& g:grid)sort(g.begin(),g.end());
        for(int j=0;j<n;j++){
            int column=0;
            for(int i=0;i<m;i++)column=max(column,grid[i][j]);
            answer+=column;
        }
        return answer;
    }
};