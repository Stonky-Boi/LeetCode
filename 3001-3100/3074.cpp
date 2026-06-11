class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<>());
        int apples=0;
        for(int a:apple)apples+=a;
        int boxes=0;
        for(int i=0;i<capacity.size();i++){
            if(apples==0)break;
            boxes++;
            apples-=min(apples,capacity[i]);
        }
        return boxes;
    }
};