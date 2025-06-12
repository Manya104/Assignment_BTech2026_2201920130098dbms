class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int mini=INT_MIN;
        while(st<nums.size()){
            mini=max(mini,abs(nums[st]-nums[end]));
            if(end==nums.size()-1){
                end=0;
                st++;
                continue;
            }
            st++;
            end++;
        }
        return mini;
    }
};