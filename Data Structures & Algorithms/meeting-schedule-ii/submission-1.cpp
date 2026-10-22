/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            if(a.end!=b.end) return a.end<b.end;
            return a.start<b.start;
        });

        multiset<int> st;

        for(auto &i: intervals){
            auto up = st.upper_bound(i.start);
            if(up==st.begin()){
                 st.insert(i.end);
                 continue;
            }

            st.erase(--up);
            st.insert(i.end);
        }

        return st.size();
    }
};
