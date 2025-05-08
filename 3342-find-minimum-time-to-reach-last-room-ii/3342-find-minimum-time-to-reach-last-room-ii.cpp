class Solution 
{
    static constexpr std::array<int, 4> dx = {0, 1, -1, 0};
    static constexpr std::array<int, 4> dy = {1, 0, 0, -1};

    bool isValid(const int i,
                 const int j,
                 const int n,
                 const int m) const
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void addAdjicent(std::priority_queue<std::tuple<int, int, int, int>, 
                                         std::vector<std::tuple<int, int, int, int>>, 
                                         std::greater<>>& pq,
                    const std::vector<std::vector<int>>& moveTime,
                    std::vector<std::vector<bool>>& visited,
                    const int x,
                    const int y,
                    const int cost,
                    const int level)
    {
        const int n = moveTime.size();
        const int m = moveTime[0].size();
        for(int i = 0; i < 4; i++)
        {
            const int newX = dx[i] + x;
            const int newY = dy[i] + y;
            if(!isValid(newX, newY, n, m) || visited[newX][newY]){ continue; }
            const int waitTime = std::max(0, moveTime[newX][newY] - cost);
            const int newCost = cost + waitTime + ((level % 2 == 0) ? 1 : 2);
            visited[newX][newY] = true;
            pq.emplace(newCost, level + 1, newX, newY);
        }
    }

public:
    int minTimeToReach(const std::vector<std::vector<int>>& moveTime) 
    {
        const int n = moveTime.size();
        const int m = moveTime[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::priority_queue<std::tuple<int, int, int, int>,
                            std::vector<std::tuple<int, int, int, int>>,
                            std::greater<>> pq;
        pq.emplace(0, 0, 0, 0);
        visited[0][0] = true;
        while(!pq.empty())
        {
            auto [cost, level, x, y] = pq.top();
            pq.pop();
            if(x == n - 1 && y == m - 1){ return cost; }
            addAdjicent(pq, moveTime, visited, x, y, cost, level);
        }
        return -1;
    }
};