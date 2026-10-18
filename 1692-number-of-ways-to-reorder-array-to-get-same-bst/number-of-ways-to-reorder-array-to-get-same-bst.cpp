class Solution {
public:
using ll = long long;
static constexpr int MOD = 1e9 + 7;
vector<vector<ll>> C;
ll dfs(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return 1;

    vector<int> left, right;

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[0])
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }

    ll waysLeft = dfs(left);
    ll waysRight = dfs(right);

    return C[n - 1][left.size()] * waysLeft % MOD
           * waysRight % MOD;
}

int numOfWays(vector<int>& nums) {
    int n = nums.size();

    C.assign(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        C[i][0] = C[i][i] = 1;

        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }

    return (dfs(nums) - 1 + MOD) % MOD;
}

};
