/**
definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    struct Intervalcompare{
        bool operator () (const Interval & a, const Interval & b) const{
            return a.start<b.start;
        }
    };

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), Intervalcompare());
        for(int i=0;i<intervals.size();i++)
        {
            if(ret.empty() || ret.back().end < intervals[i].start)
            {
                ret.push_back(intervals[i]);
            }else{
                ret.back().end=max(ret.back().end, intervals[i].end);
            }
        }

        return ret;
    }
};
