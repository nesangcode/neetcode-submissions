class Solution {
public:
    vector<int> dx, dy;
    vector<vector<int>> vis;
    // pacific 0, 
    void trav(int x, int y, int bw, vector<vector<int>>& heights){
        vis[x][y] |= bw;

        for(int i = 0; i < 4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=heights.size()||ny<0||ny>=heights[0].size()) continue;
            if(vis[nx][ny] & bw) continue;
            if(heights[nx][ny] < heights[x][y]) continue;
            trav(nx, ny, bw, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        dx = {1, 0, -1, 0};
        dy = {0, 1, 0, -1};

        vector<vector<int>> fin;
        vis.assign(heights.size(), vector<int>(heights[0].size(), 0));
        // pacific
        for(int i = 0; i < heights.size(); i++){
            if(vis[i][0] & 1) continue;
            trav(i, 0, 1, heights);
        }
        for(int i = 0; i < heights[0].size(); i++){
            if(vis[0][i] & 1) continue;
            trav(0, i, 1, heights);
        }

        // atlantic
        for(int i = 0; i < heights.size(); i++){
            if(vis[i][heights[0].size()-1] & 2) continue;
            trav(i, heights[0].size()-1, 2, heights);
        }
        for(int i = 0; i < heights[0].size(); i++){
            if(vis[heights.size()-1][i] & 2) continue;
            trav(heights.size()-1, i, 2, heights);
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(vis[i][j] == 3) fin.push_back({i, j});
            }
        }
        return fin;
    }
};
