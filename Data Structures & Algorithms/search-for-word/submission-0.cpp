class Solution {
public:
    vector<vector<bool>> vis;
    bool trav(int x, int y, int col, vector<vector<char>> &board, string &word){
        if(board[x][y] != word[col]) return false;
        if((col+1)==word.size()) return true;
        vis[x][y] = true;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()) continue;
            if(vis[nx][ny]) continue;
            if(trav(nx, ny, col+1, board, word)){
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vis.assign(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(trav(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};
