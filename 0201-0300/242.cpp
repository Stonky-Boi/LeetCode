class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int> used(26,0);
        for(char c:s)used[c-'a']++;
        for(char c:t){
            if(used[c-'a']>0)used[c-'a']--;
            else return false;
        }
        return true;
    }
};