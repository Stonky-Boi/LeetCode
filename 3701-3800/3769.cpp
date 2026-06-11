class Solution {
public:
    int reflection(int n){
        int ref=0;
        while(n>0){
            ref=(ref<<1)|(n&1);
            n>>=1;
        }
        return ref;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int refA=reflection(a);
            int refB=reflection(b);
            if(refA==refB)return a<b;
            return refA<refB;
        });
        return nums;
    }
};