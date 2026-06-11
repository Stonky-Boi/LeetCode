class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> answer;
        int total=rows*cols;
        int row=rStart;
        int column=cStart;
        answer.push_back({row,column});
        int length=1;
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        while(answer.size()<total){
            for(int i:{0,1,2,3}){
                int moves=length;
                for(int steps=0;steps<moves;steps++){
                    row+=dr[i];
                    column+=dc[i];
                    if(row>=0 &&row<rows &&column>=0 &&column<cols){
                        answer.push_back({row,column});
                        if(answer.size()==total)return answer;
                    }
                }
                if(i%2==1)length++;
            }
        }
        return answer;
    }
};