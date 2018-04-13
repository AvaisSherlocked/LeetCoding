//
//  80.Remove Duplicates from Sorted Array II.cpp

//
//  Created by Ava on 2018/4/13.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int total=1;
        int n=nums.size();
        if(n <= 2)
            return n;
        for(int i=1;i<n;i++){
            if(i==1 || nums[i] != nums[total-2]){  // !! nums[total-2] not nums[i-2] !!
                nums[total++] = nums[i];
            }
        }
        return total;
    }
};
