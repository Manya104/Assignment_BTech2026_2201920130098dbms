class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // constant vector map
        vector<int> mp(10001, -1);
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        vector<int> cumuSum(n, 0);
        cumuSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumuSum[i] = nums[i] + cumuSum[i - 1];
        }

        while (j < n) {
            // i posiition update
            i = max(i,mp[nums[j]] + 1);
            int jthsum = cumuSum[j];
            int ithsum = i - 1 < 0 ? 0 : cumuSum[i - 1];
            int subarraysum = jthsum - ithsum;
            maxi = max(maxi, subarraysum);
            mp[nums[j]] = j;
            j++;
        }
        return maxi;
    }
    /*
        int maximumUniqueSubarray(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> mp;
            int i = 0, j = 0;
            int maxi = 0, maxhere = 0;

            // sliding window
            while (j < n) {
                mp[nums[j]]++;
                maxhere += nums[j];

                while (mp[nums[j]] > 1) {
                    mp[nums[i]]--;
                    maxhere -= nums[i];
                    i++;
                }

                maxi = max(maxi, maxhere);
                j++;
            }

            return maxi;
        }
    */
};