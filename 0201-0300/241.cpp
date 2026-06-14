class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> nums;
        vector<char> ops;
        int num=0;
        for(char c:expression){
            if(isdigit(c))num=num*10+(c-'0');
            else{
                nums.push_back(num);
                num=0;
                ops.push_back(c);
            }
        }
        nums.push_back(num);
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n));
        for(int i=0;i<n;i++)dp[i][i].push_back(nums[i]);
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    for(int x:dp[i][k]){
                        for(int y:dp[k+1][j]){
                            if(ops[k]=='+')dp[i][j].push_back(x+y);
                            else if(ops[k]=='-')dp[i][j].push_back(x-y);
                            else dp[i][j].push_back(x*y);
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};