class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n = nums.size(), qsz = queries.size();
       priority_queue<int, vector<int>, greater<>>pq; 
       sort(queries.begin(), queries.end());
       int q = 0;
       for(int i = 0; i < n; i++){
            while(q < qsz && queries[q][0] <= i){
                pq.push(queries[q][1]);
                q++;
            }
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            if((int)pq.size() < nums[i])return false;
            nums[i]-=pq.size();
       }
       return true;
    }
};