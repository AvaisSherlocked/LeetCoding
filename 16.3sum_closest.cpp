//
//  16.cpp
//  test2
//
//  Created by Ava on 2018/4/10.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=0; // the minimun difference between target and 3sum
        int minV=0;
        
        if(nums.size() == 3) return nums[0]+nums[1]+nums[2];
        
        minV = nums[0]+nums[1]+nums[2];  //initialize
        for(int i=0;i<nums.size()-2;i++){ //the first val
            if(i>0 && nums[i-1]==nums[i]) i++;
            int j=i+1; // the second val
            int k = nums.size()-1; //the third val
            if(abs(minV-target) > abs(nums[i]+nums[j]+nums[k]-target))
                minV = nums[i]+nums[j]+nums[k];
            while(j<k){  // one comparison a time
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;
                if(sum > target && k-1>j) k--;
                if(sum < target && j+1<k) j++;
                
                if(abs(nums[i]+nums[j]+nums[k]-target) < abs(minV-target)) minV = nums[i]+nums[j]+nums[k];
                if(j+1==k) break;
            }
        }
        
        return minV;
    }
    
    
};
