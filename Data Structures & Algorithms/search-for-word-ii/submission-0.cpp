class Solution {
public:
    struct Node{
        int cnt=0;
        Node* nxt[26];
    };
    Node* head;
    vector<string> res;
    vector<vector<bool>> vis;

    vector<int> dx;
    vector<int> dy;
    
    void insert(string &word){
        int itr = 0;
        Node* now = head;
        while(itr < word.size()){
            if(now->nxt[word[itr]-'a'] == nullptr){
                now->nxt[word[itr]-'a'] = new Node();
            }
            now=now->nxt[word[itr]-'a'];
            itr++;
        }
        (now->cnt)++;
    }

    void trav(int &x, int &y, string &str, vector<vector<char>>& board, Node* now){
        vis[x][y] = true;
        
        if(now->cnt >= 1){
            res.emplace_back(str);
            (now->cnt)--;
        }

        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()) continue;
            if(vis[nx][ny]) continue;
            if(now->nxt[board[nx][ny]-'a'] == nullptr) continue;
            str += string(1, board[nx][ny]);
            trav(nx, ny, str, board, now->nxt[board[nx][ny]-'a']);
            str.pop_back();
        }
        vis[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new Node();
        dx = {-1, 0, 1, 0};
        dy = {0, 1, 0, -1};
        vis.assign(board.size(), vector<bool>(board[0].size(), false));
        for(auto &el: words){
            insert(el);
        }
        string str = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                str += string(1, board[i][j]);
                if(head->nxt[board[i][j]-'a'] != nullptr){
                    trav(i, j, str, board, head->nxt[board[i][j]-'a']);
                }

                str.pop_back();
            }
        }

        return res;
    }
};
