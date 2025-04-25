class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int presum = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        long long ans = 0;
        for(int num : nums) {
            presum += (num % modulo) == k;
            ans += count[(presum - k) % modulo];
            count[presum % modulo] += 1;
        }
        return ans;
    }
};