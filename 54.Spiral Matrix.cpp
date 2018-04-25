//
//  54.cpp
//
//  Created by Ava on 2018/4/25.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int row = matrix.size(); int col = matrix[0].size();
        vector<vector<int>> note(row,vector<int>(col,0));
        
        int i=0,j=0;
        res.push_back(matrix[i][j]);  //push in the first value.
        note[i][j]=1;
        while(res.size()<row*col){
            while(j+1<col && note[i][j+1]==0){
                res.push_back(matrix[i][j+1]);
                note[i][j+1]=1;
                j++;
            }
            while(i+1<row && note[i+1][j]==0){
                res.push_back(matrix[i+1][j]);
                note[i+1][j]=1;
                i++;
            }
            while(j>0 && note[i][j-1]==0){
                res.push_back(matrix[i][j-1]);
                note[i][j-1]=1;
                j--;
            }
            while(i>0 && note[i-1][j]==0){
                res.push_back(matrix[i-1][j]);
                note[i-1][j]=1;
                i--;
            }
        }
        
        return res;
    }
};
