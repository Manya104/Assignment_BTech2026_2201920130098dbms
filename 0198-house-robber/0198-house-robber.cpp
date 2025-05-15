class Solution {
int dp[101];
int solve(vector<int>&nums,int ind,int n){
    if(ind>=n)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int steal=nums[ind]+solve(nums,ind+2,n);
    int skip=solve(nums,ind+1,n);
    return dp[ind]= max(steal,skip);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n);
    }
};