//  34.cpp
//  Created by Ava on 2018/5/11.
//  Copyright © 2018年 Ava. All rights reserved.
/*problem
    Given an array of integers nums sorted in ascending order, find the starting and ending position of a given
    target value.
    Your algorithm's runtime complexity must be in the order of O(log n).
    If the target is not found in the array, return [-1, -1].
 e.g.1
 Input: nums = [5,7,7,8,8,10], target = 8
 Output: [3,4]
 e.g.2
 Input: nums = [5,7,7,8,8,10], target = 6
 Output: [-1,-1]
 */

// simple way
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int Ind1 = helper(nums,target);
        int Ind2 = helper(nums,target+1)-1;
        if(nums[Ind1] == target && Ind2 >= Ind1)
            return {Ind1,Ind2};
        else
            return {-1,-1};
    }
    int helper(vector<int> nums, int target){  // to find the most left index for the target value
        int l=0;
        int r=nums.size()-1;
        int mid=0;
        while(l<=r){  // <= make it available when r==l
            mid=(r-l)/2 + l;
            if(nums[mid] < target)  // < not <=, not to skip the situation of "=="
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};

/* workable but unreadable*/
 class Solution {
 public:
     vector<int> searchRange(vector<int>& nums, int target) {
         vector<int> res={-1,-1};
         if(nums.size()==0) return res;
         if(nums.size()==1 && nums[0]==target) {res[0]=0;res[1]=0;return res;}
         if(target<nums[0] || target > nums[nums.size()-1]) return res;

         int l = 0;
         int r = nums.size()-1;
         int lm=(l+r)/2;
         while(lm >= 0 && (nums[lm]!= target || nums[lm-1] == target)){
             if(nums[lm] < target){
                 l = lm+1;
                 lm = (l+r)/2;
             }
             else if(nums[lm] > target){
                 r = lm-1;
                 lm = (l+r)/2;
             }
             else lm--;
             if(l>r) break;
         }
         if(nums[lm]==target) res[0] = lm;
         if(nums[0]==target) res[0] = 0;

         // for the right side
         l = 0;
         r = nums.size()-1;
         int rm=(l+r)/2;
         while(rm < nums.size() && (nums[rm]!= target || nums[rm+1]== target)){
             if(nums[rm] > target){
                 r = rm-1;
                 rm = (l+r)/2;
             }
             else if(nums[rm] < target){
                 l = rm+1;
                 rm = (l+r)/2;
             }
             else rm++;
             if(l>r) break;
         }
         if(nums[rm]==target) res[1] = rm;
         if(nums[nums.size()-1]==target) res[1] = nums.size()-1;

         return res;
     }
 };

