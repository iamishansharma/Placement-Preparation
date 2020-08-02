/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval a, Interval b) 
{
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &intervals) 
{
    if(intervals.size() < 2)
        return intervals;
        
    sort(intervals.begin(), intervals.end(), comp);
    
    int first = 0;
    
    for(int second = 1; second < intervals.size(); second++) 
    {
        if(intervals[second].start <= intervals[first].end) 
            // We merge the second interval into the first one and modify the first interval to reflect it. 
            intervals[first].end = max(intervals[second].end, intervals[first].end);
        else 
        {
            // No overlap between first and second. Move forward. 
            ++first;
            
            intervals[first].start = intervals[second].start;
            intervals[first].end = intervals[second].end;
        }
        
        for(int i=0; i<intervals.size(); i++)
            cout<<intervals[i].start<<" "<<intervals[i].end<<" ";
        cout<<endl;
    }
    intervals.erase(intervals.begin() + first + 1, intervals.end());
    
    return intervals;
}
