//
//  171.cpp
//
//  Created by Ava on 2018/5/4.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum = sum*26+(s[i]-'A')+1;
        }
        return sum;
    }
};
