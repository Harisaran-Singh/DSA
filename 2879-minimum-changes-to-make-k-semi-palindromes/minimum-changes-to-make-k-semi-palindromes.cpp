class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute minimum changes for every substring
        for (int len = 2; len <= n; len++) {
            for (int d = 1; d < len; d++) {
                if (len % d != 0) continue;

                int parts = len / d;

                for (int l = 0; l + len <= n; l++) {
                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        for (int j = 0; j < parts / 2; j++) {
                            int x = l + i + j * d;
                            int y = l + i + (parts - 1 - j) * d;

                            if (s[x] != s[y]) changes++;
                        }
                    }

                    cost[l][l + len - 1] =
                        min(cost[l][l + len - 1], changes);
                }
            }
        }

        // DP: dp[i][j] = minimum changes to partition
        // first i characters into j semi-palindromes

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int p = j - 1; p < i; p++) {
                    dp[i][j] = min(dp[i][j],
                                   dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};