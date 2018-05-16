//
//  137.cpp
//  test3
//
//  Created by Ava on 2018/5/16.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()/3;i++){
            if(nums[3*i] == nums[3*i+1] && nums[3*i+1] == nums[3*i+2]) continue;
            return nums[3*i];
        }
        return nums[nums.size()-1];
    }
};
