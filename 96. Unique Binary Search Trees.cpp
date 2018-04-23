//
//  96.cpp
//  test3
//
//  Created by Ava on 2018/4/23.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int numTrees(int n) {
        /*
         DP problem: thinking like this
         1: F(n) means that the line contains n nodes at one side
         2: take one node out, so it became F(n-1)*F(1), that one node has F(1) different ways of building the BST
         3: take one node out step by step, all possible ways are F(n)*F(0)+F(n-1)*F(1)+ … + F(1)*F(n-1)+F(0)*F(n)
         */
        
        int res[n+1]={0};
        res[0]=1;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=i;k++){
                res[i] += res[k-1]*res[i-k];
            }
        }
        return res[n];
    }
};
