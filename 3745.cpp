class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,min1=INT_MAX;
        for(int n:nums){
            if(n>max1){
                max2=max1;
                max1=n;
            }
            else if(n>max2)max2=n;
            if(n<min1)min1=n;
        }
        return max1+max2-min1;
    }
};