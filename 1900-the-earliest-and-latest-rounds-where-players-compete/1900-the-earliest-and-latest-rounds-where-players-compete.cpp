class Solution {
    int minAns = INT_MAX, maxAns = INT_MIN;
    void dfs(int mask, int i, int j, int first, int second, int round, int n) {
        while(i < j && (((mask >> i) & 1) == 0)) i++;
        while(i < j && (((mask >> j) & 1) == 0)) j--;
        if(i >= j) {
            dfs(mask, 0, n - 1, first, second, round + 1, n);
        } else if(i == first && j == second) {
            minAns = min(minAns, round);
            maxAns = max(maxAns, round);
        } else {
            if(i != first && i != second) {
                dfs(mask ^ (1 << i), i + 1, j - 1, first, second, round, n);
            }
            if(j != first && j != second) {
                dfs(mask ^ (1 << j), i + 1, j - 1, first, second, round, n);
            }
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        dfs((1 << n) - 1, 0, n - 1, firstPlayer - 1, secondPlayer - 1, 1, n);
        return {minAns, maxAns}; 
    }
};