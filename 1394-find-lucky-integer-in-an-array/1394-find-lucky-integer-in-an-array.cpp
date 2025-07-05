class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i = 0;i < arr.size();i++){
            mp[arr[i]]++;
        }

        int ans = -1;
        for(auto&[first,second]:mp){
            if(first == second && ans < first){
                ans = first;
            }
        }
        return ans;
    }
};