class Solution {
public:
    bool isTrue(int i, int j, int balance, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i>=m || j>=n) return false;
        if(balance<0) return false;
        if(i==m-1 && j==n-1) return balance==0;
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        bool down,right;
        down = right = false;
        if(j<n-1){
            int add = grid[i][j+1]=='('?1:-1;
            right = isTrue(i,j+1,balance+add,grid,dp);
        }
        if(i<m-1){
            int add = grid[i+1][j]=='('?1:-1;
            down = isTrue(i+1,j,balance+add,grid,dp);
        }
        return dp[i][j][balance] = down||right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n,-1)));
        int balance = grid[0][0]=='('?1:-1;
        return isTrue(0,0,balance,grid,dp);
    }
};