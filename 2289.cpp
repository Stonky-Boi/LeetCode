class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        stack<int> st;
        int answer=0;
        for(int i=n-1;i>=0;i--){
            int steps=0;
            while(!st.empty() &&nums[i]>nums[st.top()]){
                steps=max(steps+1,dp[st.top()]);
                st.pop();
            }
            dp[i]=steps;
            answer=max(answer,steps);
            st.push(i);
        }
        return answer;
    }
};