/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        bool canAttendMeetings(vector<Interval>& intervals) {
            if (intervals.size() == 0) return true;
            sort(intervals.begin(), intervals.end(),
                    [](const Interval& a, const Interval& b) -> bool
                    {
                    return a.start < b.start; // sort based on start time, so [0, 10] < [10, 12]
                    });
            // after the sort, smallest start time will preceed
            int end = intervals[0].end; // keep track of the current latest end time
            for (unsigned i = 1; i < intervals.size(); ++i) {
                if (intervals[i].start < end) return false; // there is an intersection
                else end = intervals[i].end; // no intersection, so update end
            }
            return true;
        }
};
