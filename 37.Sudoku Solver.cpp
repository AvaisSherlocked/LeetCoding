//
//  37.cpp
// reference: sumanth232
//  Created by Ava on 2018/4/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
    int Row[9][9],Col[9][9],Block[9][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        memset(Row,0,sizeof(Row));
        memset(Col,0,sizeof(Col));
        memset(Block,0,sizeof(Block));
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'0'-1;  // since num is the second index
                    Row[i][num] = 1;  //means that the num exists
                    Col[j][num] = 1;
                    Block[i/3*3+j/3][num]=1;
                }
            }
        }
        SudokuFilling(board,0,0);   // to fill the blank
    }
    
    bool SudokuFilling(vector<vector<char>>& board,int i, int j){
        if(i==9) return true;
        if(j==9) return SudokuFilling(board,i+1,0);
        if(board[i][j] != '.') return SudokuFilling(board,i,j+1);
        
        for(int d =0;d<9;d++){
            if(!(Row[i][d] || Col[j][d] || Block[i/3*3+j/3][d])){
                board[i][j]='0'+d+1;         // try one digit
                Row[i][d]=1; Col[j][d] = 1; Block[i/3*3+j/3][d]=1;
                if(SudokuFilling(board,i,j+1)) return true;  // try the second
                board[i][j]='.'; // important to get the '.' back
                Row[i][d]=0; Col[j][d] = 0; Block[i/3*3+j/3][d]=0;
            }
        }
        return false;
    }
    
};
