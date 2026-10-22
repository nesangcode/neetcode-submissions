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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](Interval &a, Interval &b){
            if(a.start != b.start) return a.start < b.start;
            return a.end < b.end;
        });

        for(int i = 1; i < intervals.size(); i++){
            auto &now = intervals[i];
            auto &prev = intervals[i-1];
            if(now.start < prev.end) return false;
        }
        return true;
    }
};
