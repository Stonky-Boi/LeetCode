class Solution {
public:
    char findKthBit(int n, int k) {
        bool flip=false;
        int length=(1<<n)-1;
        while(length>1){
            int m=length/2+1;
            if(k==m)return flip?'0':'1';
            if(k>m){
                k=length-k+1;
                flip=!flip;
            }
            length/=2;
        }
        return flip?'1':'0';
    }
};