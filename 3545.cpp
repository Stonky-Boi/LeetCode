class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> frequency;
        for(char c:s)frequency[c]++;
        if(frequency.size()<=k)return 0;
        vector<int> freq;
        for(auto& [_,f]:frequency)freq.push_back(f);
        sort(freq.begin(),freq.end());
        int deletions=0;
        for(int i=0;i<freq.size()-k;i++)deletions+=freq[i];
        return deletions;
    }
};