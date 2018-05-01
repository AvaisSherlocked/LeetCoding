//
//  164.cpp
//
//  Created by Ava on 2018/5/1.
//  Copyright © 2018年 Ava. All rights reserved.
//

// 10 ms
 class Solution {
 public:
     int maximumGap(vector<int>& nums) {
         if(nums.size()<2) return 0;
         sort(nums.begin(),nums.end());
         int max=0;
         for(int i=1;i<nums.size();i++){
             int gap = nums[i]-nums[i-1];
             if(gap > max) max = gap;
         }
         return max;
     }
 };

