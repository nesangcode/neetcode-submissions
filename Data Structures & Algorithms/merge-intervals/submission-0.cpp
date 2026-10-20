class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        vector<vector<int>> fin;
        int n = intervals.size();

        while(i < intervals.size()){
            vector<int> ni = intervals[i];
            while(i<n&&intervals[i][0]<=ni[1]){
                ni[0] = min(ni[0], intervals[i][0]);
                ni[1] = max(ni[1], intervals[i][1]);
                i++;
            }
            fin.push_back(ni);
        }
        return fin;
    }
};
