//
//  70.cpp
//
//  Created by Ava on 2018/4/24.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        double sum = (pow((1+sqrt(5))/2,n+1)-pow((1-sqrt(5))/2,n+1))/sqrt(5);
        return (int)sum;
    }
};
