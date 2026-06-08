class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        vector<int> digits;
        for(char c:s)digits.push_back(c-'0');
        sort(digits.begin(),digits.end());
        int num1=0,num2=0;
        for(int i=0;i<digits.size();i++){
            if(i%2==0)num1=num1*10+digits[i];
            else num2=num2*10+digits[i];
        }
        return num1+num2;
    }
};