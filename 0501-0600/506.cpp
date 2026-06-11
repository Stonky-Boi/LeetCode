class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int,int>> athlete(n);
        for(int i=0;i<n;i++)athlete[i]={score[i],i};
        sort(athlete.begin(),athlete.end(),greater<>());
        vector<string> answer(n);
        for(int i=0;i<n;i++){
            int index=athlete[i].second;
            if(i==0)answer[index]="Gold Medal";
            else if(i==1)answer[index]="Silver Medal";
            else if(i==2)answer[index]="Bronze Medal";
            else answer[index]=to_string(i+1);
        }
        return answer;
    }
};