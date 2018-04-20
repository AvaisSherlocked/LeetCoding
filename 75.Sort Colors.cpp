//
//  75.cpp
//  4ms (beats 100%)
//
//  Created by Ava on 2018/4/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size()){
                if(nums[i]>nums[j])
                {
                    int tmp=nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                j++;
            }
        }
    }
};
