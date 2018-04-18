//
// 38.cpp
//  test3
//
//  Created by Ava on 2018/4/18.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    string countAndSay(int n) {
        string val="1";
        if(n==1) return val;
        int i=1;
        string res="";
        while(i<n){
            int j=0;
            if(res != "") {val=res;res="";} // important to reset res
            while(j<val.size()){
                int count=1;
                char obj=val[j];
                while(j+1<val.size() && obj==val[j+1]){j++;count++;}
                
                res += to_string(count); // very important to use to_string();
                res += obj; //add in obj
                j++;
            }
            i++;
        }
        return res;
    }
};
