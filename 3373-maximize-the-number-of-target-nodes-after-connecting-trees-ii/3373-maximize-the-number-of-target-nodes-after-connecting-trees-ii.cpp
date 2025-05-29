class Solution {
public:
    unordered_map<int, vector<int>>
    getAdjacenyList(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& oneMarkedCount, int& zeroMarkedCount) {
        // now check is the node is marked as zero or what
        if (mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }

        // now explore all neighbours of curr and mark alternatively
        for (auto& ngbr : adj[curr]) {
            if (ngbr != parent) {
                mark[ngbr] =
                    (mark[curr] == 0) ? 1 : 0; // marked for alternate nature
                // now same dfs call with curr ans ngbr and make curr as parent
                // of ngbr
                dfs(ngbr, adj, curr, mark, oneMarkedCount, zeroMarkedCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        // no of nodes for TreeA
        int N = edges1.size() + 1;
        // for TreeB
        int M = edges2.size() + 1;

        // now we have to create adj list for two trees indivisually
        unordered_map<int, vector<int>> adjA = getAdjacenyList(edges1);
        unordered_map<int, vector<int>> adjB = getAdjacenyList(edges2);

        // now we have got both adj list now we can call dfs on each
        // for that we have to take one mark vector to mark zeroCount and
        // oneCount the logic is we are going to mark the odd index node with
        // ones and even with ones so two zero index nodes are on even distance
        // and same for two one index
        // 0    1    0    1    0
        // 0 -> 1 -> 2 -> 3 -> 4

        // mark of size N and initially no one is marked so -1 for all
        vector<int> markA(N, -1);
        int oneMarkedCountA = 0;
        int zeroMarkedCountA = 0;
        markA[0] = 0; // mark 0th node as 0
        // (starting node (curr), adj list, parent(initially -1 as starting node
        // has no parent),marking vector to mark 0 and 1, and counters)
        dfs(0, adjA, -1, markA, oneMarkedCountA, zeroMarkedCountA);

        // now make same as above for TreeB
        vector<int> markB(M, -1);
        int oneMarkedCountB = 0;
        int zeroMarkedCountB = 0;

        markB[0] = 0; // mark 0th node as 0
        // (starting node (curr), adj list, parent(initially -1 as starting node
        // has no parent),marking vector to mark 0 and 1, and counters)
        dfs(0, adjB, -1, markB, oneMarkedCountB, zeroMarkedCountB);

        // From Tree B, choose the maximum group size (either 0-marked or
        // 1-marked) Because we can add that group into Tree A safely (no
        // adjacent conflicts)
        int maxEleFromTree2 = max(oneMarkedCountB, zeroMarkedCountB);

        //  For each node in Tree A, calculate total max nodes that can be added
        //  from Tree B
        vector<int> res(N);
        for (int i = 0; i < N; i++) {
            // If current node is 0-marked, add 0-marked nodes from Tree A + max
            // group from Tree B If current node is 1-marked, add 1-marked nodes
            // from Tree A + max group from Tree B
            res[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) +
                     maxEleFromTree2;
        }
        return res;
    }
};