class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(int i:s) freq[i]++;
        
        priority_queue<int,vector<int>,greater<int>> minPQ;
        priority_queue<int> maxPQ;
        
        for(auto& [ch,count]: freq){
            if(count%2==0) minPQ.push(count);
            else maxPQ.push(count);
        }
        if(minPQ.empty()||maxPQ.empty()) return 0;

        return maxPQ.top()-minPQ.top();
    }
};