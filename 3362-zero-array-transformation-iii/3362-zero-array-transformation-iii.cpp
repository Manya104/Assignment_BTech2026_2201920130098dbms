class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
        // we are passing lamda to select sorting logic
        sort(queries.begin(),queries.end(),[](const vector<int> &a, vector<int> &b){
            return a[0]<b[0];
        });
        //we need some data structure find longest queries
        //priority_queue comes handy which considers the value we storing in it as its priority. So largest number will be at top.
        priority_queue<int> heap;//Dont get confused it also called heap
        //if we process queries directly on nums array we get TLE to understand this you have to go t0 20 May 2025 daily problem.So we need difference array
        vector<int> diff(nums.size()+1,0);
        int operations = 0;
        for(int i  = 0, j = 0 ; i < nums.size(); ++i){
            operations += diff[i];
            //need your attention here. This loop allows us to see all queries contribute to make ith index 0
            while(j<queries.size() && queries[j][0]==i){
                heap.push(queries[j][1]);
                ++j;
            }
            //we are counting opertaion that we can do to make elment zero in array at index i from selected queries
            while(operations<nums[i]&&!heap.empty()&&heap.top()>=i){
                operations+=1;
                diff[heap.top()+1]-=1;
                heap.pop();
            }
            //this is where we are checking can we make array zero
            if(operations<nums[i]){
                    return -1;
            } 
        }
        //this is the garbage left in the heap lets return it(we will have queries which doesnot contribute to make nums[i] 0  in heap)
        return heap.size();
    }
};