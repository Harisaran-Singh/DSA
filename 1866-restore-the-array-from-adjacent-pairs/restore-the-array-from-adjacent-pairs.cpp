class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>& adj,unordered_set<int>& vis,vector<int>& ans){
        vis.insert(node);
        ans.push_back(node);
        for(int u:adj[node]) if(!vis.count(u)) dfs(u,adj,vis,ans);
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        for(auto& it:adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int node;
        for(auto& it:adj) if(it.second.size()==1) node = it.first;
        vector<int> ans;
        unordered_set<int> vis;
        dfs(node,adj,vis,ans);
        return ans;
    }
};