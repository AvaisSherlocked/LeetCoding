//
//  53.cpp
//  test3
//
//  Created by Ava on 2018/4/24.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(sum > max) max=sum;
            if(sum < 0) sum=0;
        }
        return max;
    }
};
