//
//  45.cpp
//
//  Created by Ava on 2018/5/7.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int c=1;
        int step=nums[0];
        int pos=0;
        while(pos+step<nums.size()-1){
            int max=0;
            int maxI =0;
            for(int i=pos+1;i<=pos+step;i++){
                if(nums[i]+i-pos > max){
                    max = nums[i]+i-pos;
                    maxI = i;
                }
            }
            pos = maxI;
            step = nums[maxI];
            c++;
        }
        return c;
    }
};
