//
//  198.cpp
//
//  Created by Ava on 2018/5/6.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int no=0,ne=0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0)
                no = max(no+nums[i],ne);
            else
                ne = max(ne+nums[i],no);
        }
        return max(no,ne);
    }
};
