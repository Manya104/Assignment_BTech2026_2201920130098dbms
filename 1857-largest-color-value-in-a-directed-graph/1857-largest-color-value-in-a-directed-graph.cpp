class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        int m=edges.size();
        int vis=0;
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        for(int i=0;i<m;i++){
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(27,0));
        int maxi=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis++;
            dp[u][colors[u]-'a']++;
            maxi=max(maxi,dp[u][colors[u]-'a']);
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
                for(int k=0;k<27;k++){
                    dp[v][k]=max(dp[v][k],dp[u][k]);
                }
            }
        }
        if(vis==n){
        return maxi;
        }
        else{
            return -1;
        }
    }
};