class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int number=1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        while(top<=bottom &&left<=right){
            for(int column=left;column<=right;column++)matrix[top][column]=number++;
            top++;
            for(int row=top;row<=bottom;row++)matrix[row][right]=number++;
            right--;
            if(top<=bottom){
                for(int column=right;column>=left;column--)matrix[bottom][column]=number++;
                bottom--;
            }
            if(left<=right){
                for(int row=bottom;row>=top;row--)matrix[row][left]=number++;
                left++;
            }
        }
        return matrix;
    }
};