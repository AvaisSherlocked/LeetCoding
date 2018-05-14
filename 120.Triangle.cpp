//
//  120.cpp
//
//  Created by Ava on 2018/5/14.
//  Copyright © 2018年 Ava. All rights reserved.
//

/*
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
        [2],
       [3,4],
      [6,5,7],
     [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        vector<int> row(triangle.back()); // the last row of triangle
        for(int r=triangle.size()-2;r>=0;r--){
            for(int i=0;i<=r;i++){
                row[i] = min(row[i],row[i+1])+triangle[r][i];
            }
        }
        return row[0];
    }
};
