//
//  35.cpp
//
//  Created by Ava on 2018/4/19.
//  Copyright © 2018年 Ava. All rights reserved.
//
9ms dichotomy
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        
        int first=0,second=nums.size()-1;
        int mid = first+second >>1;
        while(first<=second){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) first = mid+1;
            if(nums[mid]>target) second = mid-1;
            mid = first+second >>1; // cool~ bit operation, >>1 means move right 1 bit./ Euqals to divide by 2
        }
        return first;
    }
};
