class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> st[26];

        function<void(int, int)> dfs = [&](int u, int p) {
            int c = s[u] - 'a';

            st[c].push_back(u);

            for(int v : adj[u]) {
                dfs(v, u);
            }

            int newParent = p;

            if(st[c].size() > 1) {
                newParent = st[c][st[c].size() - 2];
            }

            if(newParent != -1) {
                ans[newParent] += ans[u];
            }

            st[c].pop_back();
        };

        dfs(0, -1);

        return ans;
    }
};