class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    bool trav(int now){
        vis[now] = 2;

        for(auto &nxt: adj[now]){
            if(vis[nxt] == 2) return true;
            if(vis[nxt] == 1) continue;
            if(trav(nxt)) return true;
        }

        vis[now]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses+2, vector<int>());
        vis.assign(numCourses, 0);
        
        for(auto &v: prerequisites){
            adj[v[0]].emplace_back(v[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(vis[i] != 1){
                if(trav(i)) return false;
            }
        }
        return true;
    }
};
