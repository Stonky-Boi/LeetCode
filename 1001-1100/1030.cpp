class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        queue<pair<int,int>> q;
        q.push({rCenter,cCenter});
        visited[rCenter][cCenter]=true;
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            cells.push_back({r,c});
            for(int i:{0,1,2,3}){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 &&nr<rows &&nc>=0 &&nc<cols &&!visited[nr][nc]){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
        return cells;
    }
};