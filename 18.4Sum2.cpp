//
//  4Sum2.cpp
//
//  Created by Ava on 2018/4/10.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> a(4);
        if(nums.size()<4) return sol;
        sort(nums.begin(),nums.end());
        int m=nums.size();
        
        for(int i=0;i<nums.size()-3;i++){ //two -for- loops
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;  //accelerating
            if(nums[i]+nums[m-1]+nums[m-2]+nums[m-3] < target) continue;
            
            for(int j=i+1;j<nums.size()-2;j++){
                
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;  //accelerating
                if(nums[i]+nums[j]+nums[m-1]+nums[m-2] < target) continue;
                
                int obj = target-(nums[i]+nums[j]);
                int k=j+1;  // the third number
                int h=nums.size()-1;  // the fourth number
                while(k<h){  // to make sure when k+1 == h is able to come in for comarison
                    int sum = nums[k]+nums[h];
                    if(sum < obj) k++;
                    else if(sum > obj) h--;
                    else{
                        sol.push_back(vector<int>{nums[i],nums[j],nums[k],nums[h]});
                        do{k++;}while(k-1>j && nums[k-1]==nums[k]);  // do first, then compare, skip the duplicate
                        do{h--;}while(h+1<nums.size() && nums[h]==nums[h+1]);
                    }
                }
                while(j+1<nums.size()-2 && nums[j+1]==nums[j]) j++;  // skip the duplicate
            }
            while(i+1<nums.size()-3 && nums[i+1]==nums[i]) i++;
        }
        return sol;
    }
};
