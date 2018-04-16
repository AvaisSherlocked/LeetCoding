//
//  28.cpp
//
//  Created by Ava on 2018/4/15.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs = haystack.size();
        int ns = needle.size();
        int i=0,j=0;
        while(i<hs && j<ns){
            if(haystack[i] == needle[j]) i++,j++;
            else i = i-j+1, j=0;  // when not equal, i would grow by 1
        }
        return (i-j < hs-ns)?i-j:-1; // brilliant
    }
};
