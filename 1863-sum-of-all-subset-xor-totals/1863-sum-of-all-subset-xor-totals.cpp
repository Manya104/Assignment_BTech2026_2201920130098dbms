class Solution {
public:
    void solve(vector<int>&nums,int &res,int i,int val){
        if(i == nums.size()){
            res += val;
            return;
        }
        solve(nums,res,i+1,val^nums[i]); //Take the XOR of this Index
        solve(nums,res,i+1,val); // Skip the XOR of this Index

    }
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        solve(nums,res,0,0);
        return res;
    }
};