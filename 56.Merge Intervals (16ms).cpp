//   14ms
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
        
        if(s==1) return intervals;
        int Min = INT_MAX;  // Min to count the merged intevals most left
        int Maxend = INT_MIN;  // Maxend to count the merged intevals most right
        for(int i=0;i<s;i++){
            Min = INT_MAX;
            int j=0;int k=0;
            Interval Inter;
            
            for(;j<s;j++){
                if(intervals[j].start < Min && intervals[j].start >Maxend){  // it has to bigger than Maxend to avoid repetition
                    Min = intervals[j].start;
                    Inter = intervals[j];
                }
            }
            if(Min == INT_MAX) break; // when Min is still INT_MAX, it means there's no element bigger than Maxend, it has reached the end, so break
            Maxend = Inter.end;
            
            while(k<s){  // there could be more than one intervals waiting for merging
                if(intervals[k].start <= Maxend){
                    if(intervals[k].end >Maxend){
                        Maxend = intervals[k].end;
                        k=0;continue;  // find from the begin again
                    }
                }
                k++;
            }
            Inter.end = Maxend;
            res.push_back(Inter);
            
        }
        return res;
    }
};
