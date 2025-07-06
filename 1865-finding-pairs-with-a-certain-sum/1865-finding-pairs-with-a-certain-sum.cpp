class FindSumPairs {
public:
    vector<int>vec1;
    vector<int>vec2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for (auto & it: nums2){
            mp[it]++;
        }
    }
    
    void add(int index, int val) {
        mp[vec2[index]]--; // reducing the frequecy of previous item
        vec2[index]+=val;// adding the val on the index of vec2
        mp[vec2[index]]++; // now increasing the frequency of the new item after val is added.
    }
    
    int count(int tot) {
        int c = 0;
        for (auto & x : vec1){
            c += mp[tot-x]; // adding the frequency of total - x from vec2 to count to get the total count;
        }
        return c;
    }
};
// tc --> O(m+n)
// sc --> O(n)



/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */