//
//  66.cpp

//
//  Created by Ava on 2018/4/27.
//  Copyright © 2018年 Ava. All rights reserved.
//
//  5ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size()-1;
        int n=digits.size()+1;
        while(digits[end]==9 && end>=0){
            digits[end]=0;
            end--;
        }
        if(end>=0) digits[end]++;
        else{
            digits.resize(n);
            for(int i=n-1;i>0;i--){
                digits[i]=digits[i-1];
            }
            digits[0] = 1;
        }
        return digits;
    }
};
//4ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res2;
        int end = digits.size()-1;
        int n=digits.size()+1;
        while(digits[end]==9 && end>=0){
            digits[end]=0;
            res2.push_back(digits[end]);
            end--;
        }
        if(end>=0) {
            digits[end]++;
            return digits;}
        else{
            for(int i=end;i>=0;i--){
                res2.push_back(digits[i]);
            }
            res2.push_back(1);
            reverse(res2.begin(),res2.end());
            return res2;
        }
        
    }
};
