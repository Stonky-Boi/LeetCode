class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0,bottom=m-1;
        int left=0,right=n-1;
        vector<int> answer;
        while(top<=bottom &&left<=right){
            for(int column=left;column<=right;column++)answer.push_back(matrix[top][column]);
            top++;
            for(int row=top;row<=bottom;row++)answer.push_back(matrix[row][right]);
            right--;
            if(top<=bottom){
                for(int column=right;column>=left;column--)answer.push_back(matrix[bottom][column]);
                bottom--;
            }
            if(left<=right){
                for(int row=bottom;row>=top;row--)answer.push_back(matrix[row][left]);
                left++;
            }
        }
        return answer;
    }
};