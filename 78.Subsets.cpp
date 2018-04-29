//
//  78.cpp
//
//  Created by Ava on 2018/4/29.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        helper(res,0,sub,nums);
        return res;
    }
    void helper(vector<vector<int>> &res, int begin,vector<int> &sub,vector<int> nums){
        res.push_back(sub);
        for(int i=begin;i<nums.size();i++){
            sub.push_back(nums[i]);
            helper(res,i+1,sub,nums);
            sub.pop_back();
        }
    }
};
