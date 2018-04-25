//
//  59.cpp
//  test3
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        
        int i=0,j=0,num=1;
        res[i][j] = num;  //set the first value.
        
        while(num < n*n){
            while(j+1<n && res[i][j+1]==0) res[i][++j] = ++num;
            while(i+1<n && res[i+1][j]==0) res[++i][j] = ++num;
            while(j>0 && res[i][j-1]==0) res[i][--j] = ++num;
            while(i>0 && res[i-1][j]==0) res[--i][j] = ++num;
        }
        
        return res;
    }
};
