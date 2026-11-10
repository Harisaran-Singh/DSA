class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            int c1 = i>=3?dp[i-3]+9+costs[i-1]:INT_MAX;
            int c2 = i>=2?dp[i-2]+4+costs[i-1]:INT_MAX;
            int c3 = i>=1?dp[i-1]+1+costs[i-1]:INT_MAX;
            dp[i] = min({c1,c2,c3});
        }
        return dp[n];
    }
};