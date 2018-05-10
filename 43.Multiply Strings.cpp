//
//  43.cpp
//
//  Created by Ava on 2018/5/11.
//  Copyright © 2018年 Ava. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int s1 = num1.length()-1;
        int s2 = num2.length()-1;
        int s = s1+s2;
        int r=0;  // to count the number for add in next bit
        for(int i=0;i<=s;i++){
            int k=0;
            for(int j=0;j<=i;j++){
                if(i-j > s2 || j > s1) continue; // important conditions
                k += (num1[s1-j]-'0')*(num2[s2-i+j]-'0');
            }
            res = to_string((k+r)%10)+res;
            r = (r+k)/10;
        }
        if(r>0)
            res = to_string(r)+res;
        
        // clip the front '0'---has many situations
        int z=0;
        while(res[z] == '0') z++;
        if(z>0) res = res.substr(z,res.length()-1);
        if(res == "") res="0";
        return res;
    }
};
