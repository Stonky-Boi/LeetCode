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
    int monkeyMove(int n) {
        long long total=power(2,n);
        return (int)((total-2+MOD)%MOD);
    }
};