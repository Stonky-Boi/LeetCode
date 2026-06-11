class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finish=INT_MAX;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int path1=max(landStartTime[i]+landDuration[i],waterStartTime[j])+waterDuration[j];
                int path2=max(landStartTime[i],waterStartTime[j]+waterDuration[j])+landDuration[i];
                finish=min({finish,path1,path2});
            }
        }
        return finish;
    }
};