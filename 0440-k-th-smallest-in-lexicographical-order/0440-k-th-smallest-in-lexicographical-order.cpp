class Solution {
public:
int cnt(long curr,long nxt,int n){
    int countnum=0;
    while(curr<=n){
        countnum+=(nxt-curr);
        curr*=10;
        nxt*=10;
        nxt=min(nxt,long(n+1));
    }
    return countnum;
}
    int findKthNumber(int n, int k) {
        int curr=1;
         k-=1;
        while(k>0){
            int count=cnt(curr,curr+1,n);
            if(count<=k){
                curr++;
                k-=count;
            }
            else{
                curr*=10;
                k-=1;
            }
        }
        return curr;
    }
};