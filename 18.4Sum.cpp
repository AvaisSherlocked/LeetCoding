//
//  4Sum.cpp
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
        
        for(int i=0;i<nums.size()-3;i++){ //two for loops
            for(int j=i+1;j<nums.size()-2;j++){
                int obj = target-(nums[i]+nums[j]);
                int k=j+1;  // the third number
                int h=nums.size()-1;  // the fourth number
                while(k<h){  // to make sure when k+1 == h is able to come in for comarison
                    int sum = nums[k]+nums[h];
                    if(sum == obj){
                        a[0]=nums[i];
                        a[1]=nums[j];
                        a[2]=nums[k];
                        a[3]=nums[h];
                        sol.push_back(a);
                        if(k+1<h)k++; //to keep move on, in case of sum==obj but k or h can't change
                        while(k-1>j && nums[k-1]==nums[k] && k+1<h) k++;  // skip the duplicate
                        while(h+1<nums.size() && nums[h]==nums[h+1] && h-1>j) h--;
                    }
                    if(k+1==h) break;
                    if(sum < obj) k++;
                    if(sum > obj) h--;
                }
                while(j+1<nums.size()-2 && nums[j+1]==nums[j]) j++;  // skip the duplicate
            }
            while(i+1<nums.size()-3 && nums[i+1]==nums[i]) i++;
        }
        return sol;
    }
};
