class Solution {
public:
    vector<int> dx, dy;
    int islandPerimeter(vector<vector<int>>& grid) {
        dx = {-1, 0, 1, 0};
        dy = {0, 1, 0, -1};
        int sum=0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]==0) continue;
                for(int k = 0; k < 4; k++){
                    int x=i+dx[k], y=j+dy[k];
                    if(x<0||x>=grid.size()||y<0||y>=grid[0].size()){
                        ++sum;
                        continue;
                    }
                    if(grid[x][y]==0){
                        ++sum;
                        continue;
                    }
                }
            }
        }
        return sum;
    }
};