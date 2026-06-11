class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> answer;
        int min_diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            int curr_diff=arr[i]-arr[i-1];
            if(curr_diff<min_diff){
                min_diff=curr_diff;
                answer.clear();
                answer.push_back({arr[i-1],arr[i]});
            }
            else if(curr_diff==min_diff)answer.push_back({arr[i-1],arr[i]});
        }
        return answer;
    }
};