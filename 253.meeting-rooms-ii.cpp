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
        int minMeetingRooms(vector<Interval>& intervals) {
            if (intervals.size() == 0) return 0;
            sort(intervals.begin(), intervals.end(),
                    [](const Interval& a, const Interval& b) -> bool
                    {
                    return a.start < b.start; // sort based on start time, so [0, 10] < [10, 12]
                    });
            // after the sort, smallest start time will preceed
            // max queue: smallest value store at the top
            priority_queue<int, vector<int>, std::greater<int>> pq;
            for (unsigned i = 1; i < intervals.size(); ++i) {
                // top always store the earliest end time, if the start time is greater than that
                // we don't need to allocate another room, and update the new end time to the pq
                if (intervals[i].start >= pq.top()) pq.pop();
                pq.push(intervals[i].end);
            }
            return pq.size();
        }
};
