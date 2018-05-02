//
//  168.cpp
//
//  Created by Ava on 2018/5/3.
//  Copyright © 2018年 Ava. All rights reserved.
//

//3 ms
 class Solution {
 public:
     string convertToTitle(int n) {
         string res;
         int c=0;
         double x=n;
         while(x/26 > 1){
             c++;
             x = x-pow(26,c+1);  // remember this
         }
         for(int i=c;i>0;i--){
             int d = n/pow(26,i);
             if(n==d*pow(26,i)) d--;
             res += 'A'+d-1; // and this minus 1
             n = n-d*pow(26,i);
         }
         res += 'A'+n-1;
         return res;
     }
 };
//2 ms
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        int d=0;
        int r=n%26;
        while(n>0){
            n -= 1;
            r = n%26;
            d = n/26;
            char s= 'A'+r;
            res = s+res;
            n = d;
        }
        return res;
    }
};
