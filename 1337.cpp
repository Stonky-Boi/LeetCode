class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<pair<int,int>> strength(n);
        for(int i=0;i<n;i++){
            int soldiers=0;
            for(int cell:mat[i])soldiers+=cell;
            strength[i]={soldiers,i};
        }
        sort(strength.begin(),strength.end());
        vector<int> answer(k);
        for(int i=0;i<k;i++)answer[i]=strength[i].second;
        return answer;
    }
};