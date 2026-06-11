class Solution {
public:
    static int count_bits(int n){
        int count=0;
        while(n>0){
            n&=(n-1);
            count++;
        }
        return count;
    }
    static bool compare(int a,int b){
        int bits1=count_bits(a);
        int bits2=count_bits(b);
        if(bits1==bits2)return a<b;
        return bits1<bits2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};