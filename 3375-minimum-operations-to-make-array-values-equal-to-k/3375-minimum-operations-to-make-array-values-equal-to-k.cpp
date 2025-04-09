class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int>m;  
        for(auto it:nums)
            m[it]++;
        if(m.begin()->first<k)  return -1;
        if(m.begin()->first==k) return m.size()-1;
        return m.size();
    }
};