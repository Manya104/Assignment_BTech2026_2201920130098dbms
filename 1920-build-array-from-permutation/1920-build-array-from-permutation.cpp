class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        
        // Encode both old and new values into nums[i]
        for (int i = 0; i < n; ++i) {
            nums[i] += (nums[nums[i]] % n) * n;
        }

        // Extract only the new value
        for (int i = 0; i < n; ++i) {
            nums[i] /= n;
        }

        return nums;
    }
};