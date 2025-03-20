class Solution {
    vector<int> dsu;
    int getParent(int a) { return dsu[a] == a ? a : dsu[a] = getParent(dsu[a]); }

    void join(int a, int b) { dsu[getParent(a)] = getParent(b); }

    bool same(int a, int b) { return getParent(a) == getParent(b); }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu.resize(n);
        ranges::iota(dsu, 0);
        for (auto& e : edges) join(e[0], e[1]);
        
        vector<int> best(n, -1);
        for (auto& e : edges) best[getParent(e[0])] &= e[2];

        vector<int> result;
        for (auto& q : query) result.push_back(same(q[0], q[1]) ? best[getParent(q[0])] : -1);
        return result;
    }
};