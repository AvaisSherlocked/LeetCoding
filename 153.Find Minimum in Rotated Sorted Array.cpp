//
//  154.cpp
//
//  Created by Ava on 2018/4/30.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min)
                min = nums[i];
        }
        return min;
    }
};
