class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,r=num;
        while(l<=r){
            int m=l+(r-l)/2;
            long long p=1ll*m*m;
            if(p==num)return true;
            else if(p<num)l=m+1;
            else r=m-1;
        }
        return false;
    }
};