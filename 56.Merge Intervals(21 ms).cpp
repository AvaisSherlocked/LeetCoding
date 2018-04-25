// 20ms+
//  56.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int s = intervals.size();
        if(s<=1) return intervals;
        
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;}); // remember this
        res.push_back(intervals[0]);
        for(int i=1;i<s;i++){
            if(res.back().end >= intervals[i].start)
                res.back().end = max(intervals[i].end,res.back().end); // also need to compare this, e.g. {[1,4],[2,3]}
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
