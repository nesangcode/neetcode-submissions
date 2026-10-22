class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        vector<int> fin;
        int x=0,y=0;
        int nowi=0;
        while(true){
            fin.emplace_back(matrix[x][y]);
            matrix[x][y]=-101;
            int nx = x+dx[nowi];
            int ny = y+dy[nowi];
            if(nx<0||nx>=matrix.size()||ny<0||ny>=matrix[0].size()
            ||matrix[nx][ny]==-101){
                (nowi += 1) %= 4;
                nx = x+dx[nowi];
                ny = y+dy[nowi];
            }

            if(nx<0||nx>=matrix.size()||ny<0||ny>=matrix[0].size()
            ||matrix[nx][ny]==-101){
                break;
            }

            x=nx,y=ny;
        }
        return fin;
    }
};
