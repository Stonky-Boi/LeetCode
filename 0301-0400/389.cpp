class Solution {
public:
    char findTheDifference(string s, string t) {
        char i=0;
        for(char c:s)i^=c;
        for(char c:t)i^=c;
        return i;
    }
};