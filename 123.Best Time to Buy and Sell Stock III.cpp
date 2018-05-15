//
//  123.cpp
//
//  Created by Ava on 2018/5/15.
//  Copyright © 2018年 Ava. All rights reserved.
/* questions:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 
 e.g.1
 Input: [3,3,5,0,0,3,1,4]
 Output: 6
 Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 e.g.2
 Input: [1,2,3,4,5]
 Output: 4
 Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 engaging multiple transactions at the same time. You must sell before buying again.
 e.g.3
 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

/*** highest voted solution -- DP problem
 res[0]:buy
 res[1]:sell
 res[2]:buy 2
 res[3]:sell 2
 next and cur is swaping to represent the status of this time and last time
 ***/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> res(2,{INT_MIN,0,INT_MIN,0});
        int cur=0,next=1;
        for(int i=0;i<prices.size();i++){
            res[next][0] = max(res[cur][0],-prices[i]);
            res[next][1] = max(res[cur][1],res[cur][0]+prices[i]);
            res[next][2] = max(res[cur][2],res[cur][1]-prices[i]);
            res[next][3] = max(res[cur][3],res[cur][2]+prices[i]);
            swap(next,cur);
        }
        return max(res[cur][1],res[cur][3]);
    }
};
