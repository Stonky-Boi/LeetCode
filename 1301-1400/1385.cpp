class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int value=0;
        sort(arr2.begin(),arr2.end());
        for(int a:arr1){
            auto it=lower_bound(arr2.begin(),arr2.end(),a);
            bool found=false;
            if(it!=arr2.end() &&abs(*it-a)<=d)found=true;
            if(!found &&it!=arr2.begin() &&abs(*prev(it)-a)<=d)found=true;
            if(!found)value++;
        }
        return value;
    }
};