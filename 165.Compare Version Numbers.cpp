//
//  165.cpp
//
//  Created by Ava on 2018/5/1.
//  Copyright © 2018年 Ava. All rights reserved.
//

// e.g.
// "01","1" -> 0
// "1.1","1.01" ->0
//2 ms, beats 100%
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=0,n2=0,c1=0,c2=0;
        int i=0,j=0;
        while(i<version1.length() || j<version2.length()){
            if(i==version1.length()) n1 = 0;
            if(j==version2.length()) n2 = 0;
            while(version1[i]!='.' && i<version1.length()){
                n1 = n1*10 + version1[i]-'0'; // forget everytime
                i++;
            }
            while(version2[j]!='.' && j<version2.length()){
                n2 = n2*10 + version2[j]-'0'; // forget everytime
                j++;
            }
            if(n1>n2) return 1;
            else if(n1<n2) return -1;
            i++;j++;
            n1=0;n2=0;
        }
        
        return 0;
    }
};
