class Solution {
public:
    vector<int> dx, dy;
    vector<vector<bool>> vis;
    void trav(int x, int y, vector<vector<char>>& grid){
        vis[x][y] = true;
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=grid.size()||ny<0||ny>=grid[0].size()) continue;
            if(vis[nx][ny]) continue;
            if(grid[nx][ny] != '1') continue;
            trav(nx, ny, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};
        vis.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    trav(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
};
