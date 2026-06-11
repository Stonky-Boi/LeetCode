class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> freq;
        for(int a:arr1)freq[a]++;
        vector<int> answer;
        for(int a:arr2){
            while(freq[a]>0){
                answer.push_back(a);
                freq[a]--;
            }
        }
        for(auto [a,count]:freq){
            while(count--)answer.push_back(a);
        }
        return answer;
    }
};