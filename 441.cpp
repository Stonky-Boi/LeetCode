class Solution {
public:
    int arrangeCoins(int n) {
        int l=1,r=n;
        int rows=0;
        while(l<=r){
            int m=l+(r-l)/2;
            long long needed=1ll*m*(m+1)/2;
            if(needed>n)r=m-1;
            else{
                rows=m;
                l=m+1;
            }
        }
        return rows;
    }
};