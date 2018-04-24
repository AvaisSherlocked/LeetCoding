//
//  69.cpp
//
//  Created by Ava on 2018/4/24.
//  Copyright © 2018年 Ava. All rights reserved.
//
class Solution {
public:
    int mySqrt(int x) {
        long s=x/10;
        while(s*s > x)
            s = s/10;
        if(s*s == x) return s;
        else{
            long l=s;
            long r=s*10;
            if(r==0) r=10;
            s=(s+r)/2;
            while(!(s*s<=x && (s+1)*(s+1)>=x)){
                if(s*s < x){
                    l = s;
                    s = (l+r)/2;
                }
                else if(s*s > x){
                    r = s;
                    s = (l+r)/2;
                }
            }
            if((s+1)*(s+1)==x) return s+1;
            return s;
        }
    }
};
//class Solution {
//public:
//    int mySqrt(int x) {
//        long r = x;
//        long a = x;
//        while(r * r > a) {
//            r = (r + a / r) / 2;
//        }
//        return r;
//    }
//};

