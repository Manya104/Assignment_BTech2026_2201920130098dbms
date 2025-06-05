class Solution {
public:
    class Graph {
        int V;
        list<char> *l;
    public:
        Graph(int V) { //Constructor
            this->V = V;
            l = new list<char>[V];
        }

        void addEdge(char u, char v) { //Add EDGE
            l[u - 'a'].push_back(v);
            l[v - 'a'].push_back(u);
        }

        //DFS Helper
        char dfsHelper(char curr, vector<int> &vis) { //O(V+E)
            vis[curr-'a'] = 1; //MARk Visted
            char minChar = curr;

            list<char> neighbours = l[curr-'a'];
            for(char &v : neighbours) {
                if(vis[v-'a'] == 0) {
                    minChar = min(minChar, dfsHelper(v, vis)); //REUcurive CALL
                }
            }

            return minChar;
        }

        //DFS
        string dfs(string &s1) {
            string ans;

            for(int i = 0; i < s1.length(); i++) {
                char ch  = s1[i];

                vector<int> vis(26, 0);

                char minChar = dfsHelper(ch, vis);

                ans.push_back(minChar);
            }

            return ans;
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        Graph graph(26);

        for(int i = 0; i < n; i++) {
            graph.addEdge(s1[i], s2[i]);
        }

        return graph.dfs(baseStr);
    }
};