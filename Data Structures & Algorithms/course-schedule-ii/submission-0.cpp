class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj, vector<int>& ans) {
                vis[node] = 1;
                pathVis[node] = 1;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        if(dfs(it,vis,pathVis,adj,ans)) return true;
                    }else if(pathVis[it]) return true;
                }
                pathVis[node] = 0;
                ans.push_back(node);
                return false;
             }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        vector<vector<int>>adj(numCourses);
        vector<int>ans;
        for(auto vec:prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj,ans)) return {};
            }
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
