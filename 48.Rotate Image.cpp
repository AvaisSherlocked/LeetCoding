//
//  48.cpp
//  test3
//
//  Created by Ava on 2018/4/27.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n<=1) return;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];  //(i,j)->(j,n-1-i)->(n-1-i,n-1-j)->(n-1-j,i)
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
            
        }
        return;
    }
};
