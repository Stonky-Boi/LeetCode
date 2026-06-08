class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice=0,bob=0;
        for(int a:aliceSizes)alice+=a;
        for(int b:bobSizes)bob+=b;
        int diff=(bob-alice)/2;
        unordered_set<int> bob_candies(bobSizes.begin(),bobSizes.end());
        for(int a:aliceSizes){
            int needed=a+diff;
            if(bob_candies.count(needed))return {a,needed};
        }
        return {};
    }
};