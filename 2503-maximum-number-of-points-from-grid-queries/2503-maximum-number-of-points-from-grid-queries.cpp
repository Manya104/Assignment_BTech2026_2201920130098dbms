class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;

        vector<int> res(queries.size());
        int count = 0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int idx = 0;

        for (auto& [q, i] : sortedQueries) {
            while (!pq.empty() && get<0>(pq.top()) < q) {
                auto [val, x, y] = pq.top(); pq.pop();
                ++count;
                for (auto& d : dir) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.emplace(grid[nx][ny], nx, ny);
                    }
                }
            }
            res[i] = count;
        }
        return res;
    }
};