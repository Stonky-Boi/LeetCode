class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a,vector<int>& b){return a[1]>b[1];});
        int total_units=0;
        for(auto& b:boxTypes){
            int num=b[0];
            int units=b[1];
            int boxes=min(num,truckSize);
            truckSize-=boxes;
            total_units+=boxes*units;
            if(truckSize==0)break;
        }
        return total_units;
    }
};