class Solution {
public:
    using ll = long long;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    int timer = 0, LOG, n;

    void updateBIT(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int queryBIT(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int j = LOG - 1; j >= 0; j--) {
            if (!isAncestor(up[u][j], v))
                u = up[u][j];
        }

        return up[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));
        bit.assign(n + 1, 0);
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        vector<int> mask(n);
        for (int i = 0; i < n; i++)
            mask[i] = 1 << (s[i] - 'a');

        for (int i = 0; i < n; i++) {
            updateBIT(tin[i], mask[i]);
            updateBIT(tout[i] + 1, mask[i]);
        }

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int diff = mask[u] ^ newMask;

                if (diff) {
                    updateBIT(tin[u], diff);
                    updateBIT(tout[u] + 1, diff);
                    mask[u] = newMask;
                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);
                int pathMask = queryBIT(tin[u]) ^
                               queryBIT(tin[v]) ^
                               mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};