class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         int n = nums.size();
         int total = unordered_set<int>(nums.begin() , nums.end()).size();
         int cnt = 0;


         for(int i=0; i<n; i++){
            unordered_set<int> s;
            for(int j=i; j<n; j++){
                s.insert(nums[j]);

                if(s.size() == total){
                    cnt++;
                }
            }
         }
         return cnt;
    }
};