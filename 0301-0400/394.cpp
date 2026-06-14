class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string curr="";
        int num=0;
        for(char c:s){
            if(isdigit(c))num=num*10+(c-'0');
            else if(c=='['){
                counts.push(num);
                strings.push(curr);
                num=0;
                curr="";
            }
            else if(c==']'){
                int repeat=counts.top();
                counts.pop();
                string prefix=strings.top();
                strings.pop();
                string expanded="";
                while(repeat--)expanded+=curr;
                curr=prefix+expanded;
            }
            else curr+=c;
        }
        return curr;
    }
};