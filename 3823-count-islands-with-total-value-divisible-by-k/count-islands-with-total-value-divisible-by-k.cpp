class Solution {
public:
    int bfs(int r, int c,vector<vector<int>>& vis,vector<vector<int>>& grid,int k){
        int m = grid.size();
        int n = grid[0].size();
        long long sum = 1LL*grid[r][c];
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = i+dr[k];
                int nc = j+dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]!=0){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                    sum+=1LL*grid[nr][nc];
                }
            }
        }
        return sum%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) vis[i][j] = 1;
                if(grid[i][j]!=0 && vis[i][j]==0){
                    vis[i][j] = 1;
                    ans+=bfs(i,j,vis,grid,k);
                }
            }
        }
        return ans;
    }
};