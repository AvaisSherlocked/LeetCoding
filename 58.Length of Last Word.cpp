//
//  58.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0) return 0;
        int last=0;
        for(int i=0;i<s.length();i++){
            while(s[i]==' ' && i<s.length()) i++;
            if(i == s.length()) break;
            int j=0;
            while(s[i] != ' ' && i<s.length()){  // remember add in this condition
                j++;
                i++;
            }
            last = j;
        }
        return last;
    }
};
