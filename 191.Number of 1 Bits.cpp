//
//  191.cpp
//
//  Created by Ava on 2018/5/5.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n>0){
            uint32_t x=n;  // uint32_t
            int i=0;
            while(x>1){
                x = x/2;
                i++;
            }
            n = n-pow(2,i);
            c++;
        }
        return c;
    }
};
