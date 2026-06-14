class Solution {
public:
    static const long long MOD=1e9+7;
    long long power(long long base,long long exp){
        long long result=1;
        while(exp>0){
            if(exp&1)result=(result*base)%MOD;
            base=(base*base)%MOD;
            exp>>=1;
        }
        return result;
    }
    int minNonZeroProduct(int p) {
        long long max_num=(1ll<<p)-1;
        long long base=max_num-1;
        long long exp=(1ll<<(p-1))-1;
        long long answer=(max_num%MOD)*power(base%MOD,exp)%MOD;
        return (int)answer;
    }
};