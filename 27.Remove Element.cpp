//
//  27.cpp
//
//  Created by Ava on 2018/4/13.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(nums.size() == 0) return 0;
        
        int count=0;
        for(int i=0;i<n;i++){
            while(nums[i]==val && i<n) i++;
            if(i<n){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};
