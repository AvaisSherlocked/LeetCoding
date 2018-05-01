//
//  154.cpp
//
//  Created by Ava on 2018/4/30.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(begin<end){
            mid = (begin+end)/2;
            if(nums[mid]<nums[end])
                end = mid;
            else if(nums[mid]>nums[end])
                begin = mid+1;
            else
                end--;
        }
        return nums[begin];
    }
};
