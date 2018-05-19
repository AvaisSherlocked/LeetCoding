//
//  202.cpp
//  test3
//
//  Created by Ava on 2018/5/19.
//  Copyright © 2018年 Ava. All rights reserved.
//

 /* use Floyd Cycle detection algorithm to check if this is a closed cycle */
 class Solution {
 public:
     bool isHappy(int n) {
         int slow=n,fast=n;
         do{
             slow = sum(slow);
             fast = sum(fast);
             fast = sum(fast);
         }while(fast != slow);

         return fast==1?true:false;
     }
     int sum(int n){
         int sum=0;
         while(n>0){
             int i=n%10;
             sum += i*i;
             n = n/10;
         }
         return sum;
     }
 };

/* Math skill: */
/*
 1.every n <= 6 is not a happy number
 2. every number greater than 6 ends up with the sum smaller than 6
 */

class Solution {
public:
    bool isHappy(int n) {
        while(n>6){
            int sum=0;
            while(n){
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
        }
        return n==1;
    }
};
