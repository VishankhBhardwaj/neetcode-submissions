class Solution {
public:
    int helper(int u,int p,vector<vector<int>>&adj,vector<bool>&hasApple){
        int totalTime = 0;
        for(auto it:adj[u]){
            if(it == p) continue;
            int childTime = helper(it,u,adj,hasApple);
            if(childTime>0 || hasApple[it]){
                totalTime+=childTime+2;
            }
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // int n = edges.size();
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return helper(0,-1,adj,hasApple);
    }
};