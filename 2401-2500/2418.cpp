class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<pair<int,string>> people(n);
        for(int i=0;i<n;i++)people[i]={heights[i],names[i]};
        sort(people.begin(),people.end(),[](auto& a,auto& b){return a.first>b.first;});
        vector<string> answer(n);
        for(int i=0;i<n;i++)answer[i]=people[i].second;
        return answer;
    }
};