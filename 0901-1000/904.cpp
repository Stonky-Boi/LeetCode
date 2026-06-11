class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int i=0,count=0;
        for(int j=0;j<fruits.size();j++){
            freq[fruits[j]]++;
            while(freq.size()>2){
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0)freq.erase(fruits[i]);
                i++;
            }
            count=max(count,j-i+1);
        }
        return count;
    }
};