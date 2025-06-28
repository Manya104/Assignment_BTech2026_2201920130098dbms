class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: Store value and original index
        vector<pair<int, int>>arr;
        for(int i = 0; i < nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        // Step 2: Sort by value in descending order
        sort(arr.rbegin(), arr.rend());

        // Step 3: Take top k elements (value, index)
        vector<pair<int, int>>res;
        int i = 0;
        while(i < k){
            res.push_back(arr[i]);
            i++;
        }
        // Step 4: Sort top k elements by original index
        sort(res.begin(), res.end(), [](pair<int, int>a, pair<int, int>b){
            return a.second < b.second;
        });

        // Step 5: Build the result from sorted indices
        vector<int>ans;
        for(auto num : res){
            ans.push_back(num.first);
        }

        return ans;
    }
};