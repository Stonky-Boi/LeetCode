class Solution {
public:
    int lastRemaining(int n) {
        int head=1;
        int steps=1;
        int remaining=n;
        bool left=true;
        while(remaining>1){
            if(left||remaining%2==1)head+=steps;
            remaining/=2;
            steps*=2;
            left=!left;
        }
        return head;
    }
};