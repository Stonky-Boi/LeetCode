class Solution {
public:
    int minimumSum(int num) {
        vector<int> digit(4);
        int power=1000;
        for(int i=0;i<4;i++){
            digit[i]=num/power;
            num%=power;
            power/=10;
        }
        sort(digit.begin(),digit.end());
        return 10*(digit[0]+digit[1])+(digit[2]+digit[3]);
    }
};