//
//  167.cpp
//
//  Created by Ava on 2018/5/2.
//  Copyright © 2018年 Ava. All rights reserved.
//
//7 ms
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int b=0;
        int e=numbers.size()-1;
        while(numbers[b]+numbers[e] != target){
            int sum = numbers[b]+numbers[e];
            if(sum < target)
                b++;
            else if(sum > target)
                e--;
        }
        res.push_back(b+1);
        res.push_back(e+1);
        return res;
    }
};
