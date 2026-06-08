class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int a:amount){
            if(a>0)pq.push(a);
        }
        int seconds=0;
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            first--;
            second--;
            seconds++;
            if(first>0)pq.push(first);
            if(second>0)pq.push(second);
        }
        if(!pq.empty())seconds+=pq.top();
        return seconds;
    }
};