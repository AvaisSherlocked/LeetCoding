//
//  64.cpp
//
//  Created by Ava on 2018/5/12.
//  Copyright © 2018年 Ava. All rights reserved.
/* problem
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of
 all numbers along its path.
 Note: You can only move either down or right at any point in time.
 e.g.1
 Input:
 [
 [1,3,1],
 [1,5,1],
 [4,2,1]
 ]
 Output: 7
 Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> G=grid;
        G.resize(r+1,vector<int>(c,INT_MAX/2));
        for(int i=0;i<r+1;i++){
            G[i].resize(c+1,INT_MAX/2);
        }
        G[r-1][c]=0;
        G[r][c-1]=0;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                G[i][j] = min(G[i][j]+G[i+1][j],G[i][j]+G[i][j+1]);
            }
        }
        
        return G[0][0];
    }
};
