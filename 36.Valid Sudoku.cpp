//
//  36.cpp
//
//  Created by Ava on 2018/4/19.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int Row[9][9] = {0}, Col[9][9]={0},Patch[9][9]={0}; // it can also use bool type
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char tmp = board[i][j];
                if(tmp != '.'){
                    int num = tmp-'0'-1; //val in Sudoku has no zero
                    if(Row[i][num] || Col[j][num] || Patch[3*(i/3)+j/3][num])
                        return false;
                    else{
                        Row[i][num] = 1;
                        Col[j][num] = 1;
                        Patch[3*(i/3)+j/3][num]=1;
                    }
                }
            }
        }
        return true;
    }
};
