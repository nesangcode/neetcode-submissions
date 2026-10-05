class Solution {
public:
    bool trav(int now, vector<int> &vis, vector<vector<int>> &adj, string &topo){
        vis[now] = 2;

        for(auto &el: adj[now]){
            if(vis[el]==2) return false;
            if(vis[el]==1) continue;
            if(!trav(el, vis, adj, topo)) return false;
        }

        vis[now] = 1;
        topo += now+'a';
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        vector<bool> ok(26, 0);
        vector<int> vis(26, 0);
        vector<vector<int>> adj(26, vector<int>());

        if(words.size()==1){
            string fin;
            for(auto &ch: words[0]){
                if(!ok[ch-'a']){
                    fin += ch;
                    ok[ch-'a'] = true;
                }
            }
            return fin;
        }
        for(int i = 1; i < words.size(); i++){
            int x=0;
            string &prev = words[i-1];
            string &now = words[i];
            bool found = false;
            while(x<prev.size() && x<now.size()){
                if(prev[x]==now[x]){
                    ok[prev[x]-'a'] = true;
                    x++;
                    continue;
                }
                ok[prev[x]-'a'] = true;
                ok[now[x]-'a'] = true;
                if(!found) adj[prev[x]-'a'].emplace_back(now[x]-'a');
                found = true;
                x++;
            }

            if(!found && prev.size()>now.size()){
                cout << prev << '\n';
                return "";   
            }

            while(x<prev.size()){
                ok[prev[x]-'a'] = true;
                x++;
            }
            while(x<now.size()){
                ok[now[x]-'a'] = true;
                x++;
            }
        }

        string tp;

        for(int i = 0; i < 26; i++){
            if(ok[i]){
                if(vis[i]) continue;
                if(!trav(i, vis, adj, tp)){
                    return "";
                }
            }
        }

        reverse(tp.begin(), tp.end());
        return tp;
    }
};
