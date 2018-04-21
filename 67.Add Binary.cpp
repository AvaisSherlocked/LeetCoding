//
//  67.cpp
//
//  Created by Ava on 2018/4/21.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length();
        int lb = b.length();
        if(la==0) return b;
        if(lb==0) return a;
        
        ///////make them the same length
        string nb=b,na=a;
        if(la > lb)
            for(int i=0;i<la-lb;i++)
                b = '0'+b;
        else
            for(int i=0;i<lb-la;i++)
                a = '0'+a;
        string res;
        int d=0;
        for(int i=a.length()-1;i>=0;i--){
            int val = (a[i]-'0')+(b[i]-'0')+d;
            d = 0;
            if(val==0) res = '0'+res;
            else if(val==1) res = '1'+res;
            else if(val==2) { res = '0'+res; d=1;}
            else if(val==3) { res = '1'+res; d=1;}
        }
        if(d==1) res = '1'+res;
        return res;
    }
};
