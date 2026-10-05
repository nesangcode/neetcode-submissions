class Solution {
public:
    void trav(int now, vector<int> &vis, vector<vector<int>> &adj){
        vis[now] = true;
        for(auto &el: adj[now]){
            if(vis[el]) continue;
            trav(el, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());

        for(auto &v: edges){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        int sum=0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                trav(i, vis, adj);
                ++sum;
            }
        }
        return sum;
    }
};
