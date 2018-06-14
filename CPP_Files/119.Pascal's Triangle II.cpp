//
//  119.cpp
//
//  Created by Ava on 2018/4/30.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> N={1};
        if(rowIndex==0) return N;
        vector<int> Row;
        long val=1;
        for(int i=0;i<=rowIndex;i++){
            if(i==0 || i==rowIndex) val=1;
            else val = val*(rowIndex+1-i)/i;
            Row.push_back(val);
        }
        return Row;
    }
};
