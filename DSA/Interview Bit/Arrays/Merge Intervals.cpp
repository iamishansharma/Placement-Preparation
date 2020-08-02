/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector<Interval> v;
    
    int s = newInterval.start;
    int e = newInterval.end;
    
    auto i = intervals.begin();
    
    for(; i != intervals.end(); i++)
    {
        if(i->end < s)
            v.push_back(*i);
        else 
            break;
    }
    for(;i!=intervals.end();i++)
    {
        if(i->start > e)
            break;
        
        s = min(i->start, s);
        e = max(i->end, e);
    }
    
    newInterval.start = s;
    newInterval.end = e;
    
    v.push_back(newInterval);
    
    for(;i != intervals.end(); i++)
        v.push_back(*i);

    return v;
}
