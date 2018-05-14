//
//  121.cpp
//
//  Created by Ava on 2018/5/14.
//  Copyright © 2018年 Ava. All rights reserved.
//
/****
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.
 Note that you cannot sell a stock before you buy one.
 
 e.g.1
 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 
 e.g.2
 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 ****/

 //workable -- complicated version
 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         long in=INT_MAX,out=INT_MIN;
         int in_pos=0;
         int max=0;
         for(int i=0;i<prices.size();i++){
             if(prices[i]<in){
                 in = prices[i];
                 in_pos = i;
                 out = prices[i];
                 continue;
             }
             if(prices[i]>out && i>in_pos)
                 out = prices[i];

             if(out-in > max) max=out-in;
         }
         return max>0?max:0;
     }
 };
// simplified
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long min=INT_MAX;
        int res=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min = prices[i];
            if(prices[i]-min > res)
                res = prices[i]-min;
        }
        return res>0?res:0;
    }
};

