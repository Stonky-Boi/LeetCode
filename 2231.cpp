class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        priority_queue<int> even,odd;
        for(char c:s){
            int d=c-'0';
            if(d%2==0)even.push(d);
            else odd.push(d);
        }
        for(char& c:s){
            int d=c-'0';
            if(d%2==0){
                c=even.top()+'0';
                even.pop();
            }
            else{
                c=odd.top()+'0';
                odd.pop();
            }
        }
        return stoi(s);
    }
};