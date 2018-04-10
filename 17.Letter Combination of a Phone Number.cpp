//
//  Letter Combination of a Phone Number.cpp
//  test2
//
//  Created by Ava on 2018/4/10.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        string NTC[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==0) return out;
        out.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string> v_tmp;
            string s_tmp=NTC[digits[i]-'0'];
            for(int j=0; j< s_tmp.size();j++)  // the i-th digit mapping to the string
                for(int k=0;k<out.size();k++)
                    v_tmp.push_back(out[k]+s_tmp[j]);
            out = v_tmp;
        }
        return out;
    }
};
