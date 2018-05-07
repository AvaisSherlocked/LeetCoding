//
//  200.cpp
//
//  Created by Ava on 2018/5/7.
//  Copyright © 2018年 Ava. All rights reserved.
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> sign(row,vector<int>(col,0));
        int c=0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                queue<pair<int,int>> Cur;
                if(grid[i][j]=='1'&& sign[i][j]==0){  // label the '1' with right sign number
                    if(i-1>=0 && sign[i-1][j]>0)
                        sign[i][j] = sign[i-1][j];
                    if(j-1>=0 && sign[i][j-1]>0)
                        sign[i][j] = sign[i][j-1];
                    if(i+1<row && sign[i+1][j]>0)
                        sign[i][j] = sign[i+1][j];
                    if(j+1<col && sign[i][j+1]>0)
                        sign[i][j] = sign[i][j+1];
                    else
                        sign[i][j] = ++c;
                    Cur.push(pair<int,int>(i,j));
                }
                
                while(Cur.size() > 0){  // label all '1' around the signed cell
                    int a = Cur.front().first;
                    int b = Cur.front().second;
                    if(a-1>=0 && grid[a-1][b]=='1' && sign[a-1][b]==0){
                        sign[a-1][b] = sign[a][b];
                        Cur.push(pair<int,int>(a-1,b));
                    }
                    if(b-1>=0 && grid[a][b-1]=='1' && sign[a][b-1]==0){
                        sign[a][b-1] = sign[a][b];
                        Cur.push(pair<int,int>(a,b-1));
                    }
                    if(b+1<col && grid[a][b+1]=='1' && sign[a][b+1]==0){
                        sign[a][b+1] = sign[a][b];
                        Cur.push(pair<int,int>(a,b+1));
                    }
                    if(a+1<row && grid[a+1][b]=='1' && sign[a+1][b]==0){
                        sign[a+1][b] = sign[a][b];
                        Cur.push(pair<int,int>(a+1,b));
                    }
                    Cur.pop();
                }
            }
        }
        return c;
    }
};
