class Solution {
private:
    vector<int> tree;
    int n;

    void update(int n, int l, int r, int i, int v){
        if(l==r){
            tree[n]=v;
            return;
        }
        int m=l+(r-l)/2;
        if(i<=m)update(2*n,l,m,i,v);
        else update(2*n+1,m+1,r,i,v);
        tree[n]=max(tree[2*n],tree[2*n+1]);
    }
    int query(int n,int l,int r,int v){
        if(tree[n]<v)return -1;
        if(l==r)return l;
        int m=l+(r-l)/2;
        int result=query(2*n,l,m,v);
        if(result==-1)result=query(2*n+1,m+1,r,v);
        return result;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n=baskets.size();
        tree.assign(4*n,0);
        for(int i=0;i<n;i++)update(1,0,n-1,i,baskets[i]);
        int unplaced=0;
        for(int f:fruits){
            int i=query(1,0,n-1,f);
            if(i!=-1)update(1,0,n-1,i,0);
            else unplaced++;
        }
        return unplaced;
    }
};