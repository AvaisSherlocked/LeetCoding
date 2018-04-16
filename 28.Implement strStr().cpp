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
        if(ns == 0) return 0;
        for(int i =0;i<hs;i++){
            if(haystack[i] != needle[0]) continue;
            if(haystack[i]==needle[0] && ns==1) return i;
            if(haystack[i]==needle[0]){
                int k=0;
                while(k<ns && i+k<hs && haystack[i+k]==needle[k]) k++; // only use k to count, for not to change i
                if(k==ns) return i;
                else continue;
            }
        }
        return -1;
    }
};
