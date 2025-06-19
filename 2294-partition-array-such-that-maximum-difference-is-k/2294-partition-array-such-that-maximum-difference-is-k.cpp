class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int maxi=nums[0];
        int mini=nums[0];

        for (int i=1;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=max(maxi,nums[i]);
            }
            if(mini>nums[i]){
                mini=min(mini,nums[i]);
            }
            if(maxi-mini>k){
                count++;
                maxi=nums[i];
                mini=nums[i];
            }
        }

        return count;

    }
};