//
//  39.cpp
//
//  Created by Ava on 2018/4/27.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return(res);
        sort(candidates.begin(),candidates.end()); // important
        
        vector<int> fac;
        int pos=0;
        solve(candidates,target,pos,fac,res);
        return res;
    }
    void solve(vector<int>& candidates,int target,int pos,vector<int> &fac,vector<vector<int>> &res){
        if( target == 0){
            res.push_back(fac);
            return;
        }
        for(int i=pos;i<candidates.size() && target>=candidates[i];i++){
            fac.push_back(candidates[i]);
            // target = target - candidates[i]; It's very important not to perform on the val of target
            solve(candidates,target - candidates[i],i,fac,res);   // but to use target - candidates[i]
            fac.pop_back();   // backtracking, come back to last choice and choose another
        }
    }
};
