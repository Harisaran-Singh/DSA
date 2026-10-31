class Solution {
public:
    int mod = 1000000007;
    int dp[501][501][2];
    int dfs(int i, int j, vector<vector<int>>& grid, int dir){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir==0) return dfs(i,j+1,grid,1);
            else return dfs(i+1,j,grid,0);
        }
        int right = 0; int down = 0;
        if(j<n-1 && grid[i][j+1]==1) right = dfs(i+1,j+1,grid,0);
        else if(j<n-1) right = dfs(i,j+1,grid,0);
        if(i<m-1 && grid[i+1][j]==1) down = dfs(i+1,j+1,grid,1);
        else if(i<m-1) down = dfs(i+1,j,grid,1);
        return dp[i][j][dir] = (right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,grid,0);
    }
};