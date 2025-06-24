class Solution {
public:
    int ans;
    void dfs(vector<int> adj[],vector<bool>&vis,int node,string&colors,vector<vector<int>>&dp,int n){
        vis[node] = true;
        for(auto child : adj[node]){
            if(vis[child])  continue;
            dfs(adj,vis,child,colors,dp,n);
            for(int c = 0;c<26;c++){
                dp[node][c] = max(dp[node][c],dp[child][c]);
            }
        }
        for(auto child : adj[node]){
            for(int c = 0;c<26;c++){
                dp[node][c] = max(dp[child][c],dp[node][c]);
            }
        }
        dp[node][colors[node]-'a']++;
        // if(node == 5){
        //     cout<<dp[node]['n'-'a']<<"\n";
        // }
    }
    bool checkforcycle(vector<int> adj[],int node,vector<bool>&vis,vector<bool>&anc){
        vis[node] = true;
        anc[node] = true;
        bool f = false;
        for(auto child : adj[node]){
            if(anc[child]){
                return true;
            }
            if(vis[child])  continue;
            f |= checkforcycle(adj,child,vis,anc);
        }
        anc[node] = false;
        return f;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        ans = 0;
        vector<int> adj[n];
        for(int i = 0;i<edges.size();i++)
            adj[edges[i][0]].push_back(edges[i][1]);
        vector<bool> viss(n,false);
        vector<bool> anc(n,false);
        for(int i = 0;i<n;i++){
            if(viss[i]) continue;
            if(checkforcycle(adj,i,viss,anc)){
                return -1;
            }
        }
        vector<bool> vis(n,false);
        // int maxi = -1;
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i = 0;i<n;i++){
            if(vis[i])  continue;
            dfs(adj,vis,i,colors,dp,n);
        }
        for(int i = 0;i<n;i++){
            for(int c = 0;c<26;c++){
                ans = max(ans,dp[i][c]);
            }
        }
        return ans;
    }
};