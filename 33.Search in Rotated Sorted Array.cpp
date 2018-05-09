//
//  33.cpp
//
//  Created by Ava on 2018/5/10.
//  Copyright © 2018年 Ava. All rights reserved.
//
//O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int i=0,j=nums.size()-1;
        if(nums[i] == nums[j])
            return nums[i]==target?0:-1;
        if(nums[i]<nums[j]){
            if(nums[i]>target || nums[j]<target) return -1;
            while(i<=j){
                if(nums[i]<target) i++;
                if(nums[j]>target) j--;
                if(nums[i]==target) return i;
                if(nums[j]==target) return j;
            }
        }
        if(i>j) return -1;
        while(nums[i]<=target){
            if(nums[i]==target) return i;
            i++;
            if(nums[i]<nums[0]) return -1;
        }
        while(nums[j]>=target){
            if(nums[j]==target) return j;
            j--;
            if(nums[j]>nums[nums.size()-1]) return -1;
        }
        return -1;
    }
};
