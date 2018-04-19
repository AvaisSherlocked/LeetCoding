//
//  35.cpp
//
//  Created by Ava on 2018/4/19.
//  Copyright © 2018年 Ava. All rights reserved.
//

//9ms - sequence traverse
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()||target<nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        
        int i=0;
        while(i<nums.size()){
            if(nums[i]==target)
                return i;
            if(nums[i]<target && nums[i+1]>target)
                return i+1;
            i++;
        }
    }
};
