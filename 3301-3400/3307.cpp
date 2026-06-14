class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long length=1;
        int last=0;
        while(last<operations.size()&&length<k){
            length*=2;
            last++;
        }
        int shifts=0;
        for(int i=last-1;i>=0;i--){
            length/=2;
            if(k>length){
                k-=length;
                if(operations[i]==1)shifts++;
            }
        }
        return 'a'+shifts%26;
    }
};