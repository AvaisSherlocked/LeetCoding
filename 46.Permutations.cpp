//
//  46.cpp
//
//  Created by Ava on 2018/4/27.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int s=nums.size();
        vector<vector<int>> res;
        if(s==0) return res;
        res.push_back(vector<int>(1,nums[0]));
        for(int i=1;i<s;i++){
            Allswap(res,nums[i]);
        }
        return res;
    }
    void Allswap(vector<vector<int>> &res,int m){
        vector<vector<int>> res2;
        for(int i=0;i<res.size();i++){
            vector<int> item = res[i];
            item.push_back(m); // add in one more element
            res2.push_back(item);
            for(int j=item.size()-1;j>0;j--){
                item[j] = item[j-1];
                item[j-1]=m;
                res2.push_back(item);
            }
        }
        res = res2;
    }
};
