class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        int n=s.size();
        int count=0;
        for(int i=0;i<n;){
            string temp="";
            int j=i;
            while(j<n &&s[j]!=' ')temp+=s[j++];
            int rank=temp.back()-'1';
            words[rank]=temp.substr(0,temp.size()-1);
            count++;
            i=j+1;
        }
        string result="";
        for(int i=0;i<count;i++)result+=words[i]+(i==count-1?"":" ");
        return result;
    }
};