class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int size = nums.size()-2;

        for(int i = 0; i < size; i++){
            if(nums[i] + nums[i+2] == (nums[i+1]/2.0f))
                ans++;
        }

        return ans;
    }
};