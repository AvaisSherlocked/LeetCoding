//
//  136.cpp
//  test3
//
//  Created by Ava on 2018/5/16.
//  Copyright © 2018年 Ava. All rights reserved.
//
//s1
 class Solution {
 public:
     int singleNumber(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         for(int i=0;i<nums.size()/2;i++){
             if(nums[2*i]==nums[2*i+1]) continue;
             return nums[2*i];  // the single one is always in the even position
         }
         return nums[nums.size()-1];
     }
 };
//s2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(auto e : nums)
            val ^= e;   // using XOR, both 1 or 0 is 0, otherwise is 1. All same number counteract to 0.
        
        return val;
    }
};
