//
//  74.cpp
//  12ms
//
//  Created by Ava on 2018/4/28.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;  //remember the judging condition
        int m=matrix.size();
        int n=matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int i=0,j=0;
        while(target>matrix[i][n-1] && i+1<m) i++;  // compare with the last item in row
        while(target>matrix[i][j] && j+1<n) j++;
        if(target == matrix[i][j]) return true;
        else return false;
    }
};
