//
//  47.cpp
//
//  Created by Ava on 2018/4/28.
//  Copyright © 2018年 Ava. All rights reserved.
//

/**sollution thought -- backtracking
 1. Increase number one by one
 2. Skip duplicate when step into the next level
 
 e.g.[1,1,1,2,2]
 level1: remain [1,1,2]
 level2: remain [1]
       1
     /   \ 2
    1
   /  \ 2 ……
 1
   \  / 1 ……
    2
     \ 2 ……
 
     / 1 ……
   1
  /  \ 2 ……
2
  \   / 1 ……
    2
 **/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        Allswap(res,nums,0);
        return res;
    }
    
    void Allswap(vector<vector<int>> &res,vector<int> nums,int i){
        if(i==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(i!=j && nums[i]==nums[j]) continue;   // skip the duplicate
            swap(nums[i],nums[j]);
            Allswap(res,nums,i+1);
            
        }
    }
};
