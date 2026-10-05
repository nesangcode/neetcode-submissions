class Solution {
public:
    int trav(int now, int prev, vector<vector<int>> &adj, vector<int> &vis){
        int sum = 0;
        vis[now] = 2;
        for(auto &el: adj[now]){
            if(el==prev) continue;
            if(vis[el]!=0) return false;
            sum += trav(el, now, adj, vis);
        }
        return sum+1;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if((edges.size()+1) != n) return false;
        vector<int> ind(n, 0);
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        
        for(auto &v: edges){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        return trav(0, 0, adj, vis) == n;
    }
};
