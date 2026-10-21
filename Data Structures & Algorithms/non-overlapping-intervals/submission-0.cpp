class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &va, vector<int> &vb){
            if(va[1]==vb[1]){
                return va[0]<vb[0];
            }
            return va[1]<vb[1];
        });

        vector<int> now = {-1, -1};
        int take = 0;
        for(auto &v: intervals){
            if(max(now[0],v[0]) >= min(now[1],v[1])){
                ++take;
                now = v;
            }
        }
        return intervals.size()-take;
    }
};
