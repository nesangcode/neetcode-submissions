class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
            double da = (double)a[0]*a[0]+a[1]*a[1];
            double db = (double)b[0]*b[0]+b[1]*b[1];
            return da < db;
        });
        vector<vector<int>> res;
        for(int i = 0; i < k;i++){
            res.push_back(points[i]);
        }
        return res;
    }
};
