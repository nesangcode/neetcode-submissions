class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1],adj2[n+1];
        for(auto &v: trust){
            adj[v[0]].emplace_back(v[1]);
            adj2[v[1]].emplace_back(v[0]);
        }


        for(int i = 1; i <= n; i++){
            if(adj2[i].size()==(n-1) && adj[i].size()==0){
                return i;
            }
        }
        return -1;
    }
};