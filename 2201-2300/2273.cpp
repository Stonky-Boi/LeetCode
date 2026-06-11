class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> answer;
        string last="";
        for(string& w:words){
            string curr=w;
            sort(curr.begin(),curr.end());
            if(answer.empty()||curr!=last){
                answer.push_back(w);
                last=curr;
            }
        }
        return answer;
    }
};