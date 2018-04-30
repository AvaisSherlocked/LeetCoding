//
//  118.cpp
//
//  Created by Ava on 2018/4/30.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;
        res.push_back(vector<int>(1,1));
        if(numRows == 1) return res;
        
        for(int i=1;i<=numRows;i++){
            vector<int> curRow;
            vector<int> lastRow = res.back();
            if(i==1) continue;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1) curRow.push_back(1);
                else curRow.push_back(lastRow[j-1]+lastRow[j]);
            }
            res.push_back(curRow);
        }
        return res;
    }
};
