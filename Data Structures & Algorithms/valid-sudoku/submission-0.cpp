class Solution {
public:
    bool checkRec(int &a, int &b, vector<vector<char>> &board){
        bool ok[9] = {false};
        for(int i = a; i < a+3; i++){
            for(int j = b; j < b+3; j++){
                char ch = board[i][j];
                if(ch=='.') continue;
                if(ok[ch-'1']) return false;
                ok[ch-'1'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for(auto &v: board){
            bool ok[9] = {false};
            for(auto &ch: v){
                if(ch=='.') continue;
                if(ok[ch-'1']) return false;
                ok[ch-'1'] = true;
            }
        }
        // col
        for(int j = 0; j < board[0].size(); j++){
            bool ok[9] = {false};
            for(int i = 0; i < board.size(); i++){
                char ch = board[i][j];
                if(ch=='.') continue;
                if(ok[ch-'1']) return false;
                ok[ch-'1'] = true;
            }
        }

        for(int i = 0; i < board.size(); i+=3){
            for(int j = 0; j < board[i].size(); j+=3){
                if(!checkRec(i, j, board)) return false;
            }
        }
        return true;
    }
};
