class Solution {
public:

    int solve(vector<int>&v,int x){
        int l=0,h=v.size()-1;
        int op=INT_MAX;
        while(l<=h){
            int ans=0;
            int mid=(l+h)/2;
            for(int i=0;i<v.size();i++){
                if(abs(v[i]-v[mid])%x==0){
                    ans+=abs(v[i]-v[mid])/x;
                }
            }
            if(ans!=0 and op>ans){
                op=min(ans,op);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return op;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(auto i:grid){
            for(auto j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]<x and v[i]-v[i-1]!=0){
                return -1;
            }
        }
        int count=0;
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]==0){
                count++;
            }
        }
        if(count==v.size()-1){
            return 0;
        }
        int l=0,h=v.size()-1;
        int ans=INT_MAX;
        ans = min(ans,solve(v,x));
        return ans==INT_MAX?-1:ans;
    }
};