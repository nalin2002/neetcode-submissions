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
    static bool comp(Interval& a, Interval& b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n= intervals.size();
        if(n==1) return 1;
        int count =0;
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(const auto& x: intervals){
            if(!pq.empty() && pq.top()<= x.start){
                pq.pop();
            }
            pq.push(x.end);
        }
        
        return pq.size();
    }
};
