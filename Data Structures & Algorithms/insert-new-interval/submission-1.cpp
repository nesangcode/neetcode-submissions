class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        int idx = intervals.size()-1;
        while(idx > 0){
            vector<int> &now = intervals[idx];
            vector<int> &prev = intervals[idx-1];
            
            if(prev[0] < now[0]) break;
            if(prev[0]==now[0]){
                if(prev[1]==now[1]){
                    break;
                }
                if(prev[1]>now[1]){
                    swap(now, prev);
                    idx--;
                    continue;
                }
                break;
            }
            swap(now, prev);
            idx--;
        }

        for(int i = max(1, idx); i < intervals.size(); i++){
            vector<int> &now = intervals[i];
            vector<int> &prev = intervals[i-1];
            if(now[0] <= prev[1]){ // overlap
                now[1] = prev[1] = max(now[1], prev[1]);
                now[0] = prev[0];
            }
        }

        stack<vector<int>> st;

        while(!intervals.empty()){
            vector<int> &hi = intervals.back();

            if(st.empty() || st.top()[0]!=hi[0]){
                st.push(hi);
            }
            
            intervals.pop_back();
        }

        while(!st.empty()){
            intervals.push_back(st.top());
            st.pop();
        }
        return intervals;
    }
};
