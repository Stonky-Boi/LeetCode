class Solution {
public:
    double myPow(double x, int n) {
        double answer=1.0;
        long long exp=n;
        if(exp<0){
            x=1.0/x;
            exp=-exp;
        }
        while(exp>0){
            if(exp%2==1)answer*=x;
            x*=x;
            exp/=2;
        }
        return answer;
    }
};