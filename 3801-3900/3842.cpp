class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> toggled(100,false);
        for(int b:bulbs)toggled[b-1]=!toggled[b-1];
        vector<int> on;
        for(int i=0;i<100;i++){
            if(toggled[i])on.push_back(i+1);
        }
        return on;
    }
};