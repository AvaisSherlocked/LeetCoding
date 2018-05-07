//
//  55.cpp
//
//  Created by Ava on 2018/5/7.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2) return true;
        int need=1;
        for(int i=nums.size()-2;i>=0;i--){
            while(nums[i]<need){
                i--;
                need++;
            }
            if(i<0) return false;
            need = 1;
        }
        return true;
    }
};
