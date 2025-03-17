class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> a;
        for(int i:nums){
            a[i]++;
        }
        bool ans=true;
        for(auto i:a){
            if(i.second%2!=0) {
                ans=false;
                break;
            }
        }
        return ans;
    }
};