//
//  26.cpp

//
//  Created by Ava on 2018/4/12.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0 || nums[i] != nums[count-1])
                nums[count++] = nums[i];
        }
        
        return count;
    }
};
