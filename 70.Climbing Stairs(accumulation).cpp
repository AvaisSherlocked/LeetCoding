//
//  70.cpp
//
//  Created by Ava on 2018/4/24.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int climbStairs(int n) {
        long sum =0;
        if(n==1) return 1;
        if(n==2) return 2;
        long f=1;
        long s=2;
        for(int i=3;i<=n;i++){
            sum =f+s;
            f = s;
            s = sum;
        }
        return sum;
    }
};
