class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)nums[i]+=nums[i-1];
        vector<int> answer;
        for(int q:queries){
            int l=0;
            int r=nums.size()-1;
            int count=0;
            while(l<=r){
                int m=l+(r-l)/2;
                if(nums[m]<=q){
                    count=m+1;
                    l=m+1;
                }
                else r=m-1;
            }
            answer.push_back(count);
        }
        return answer;
    }
};